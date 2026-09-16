#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Package {
protected:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZip;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZip;
    double weight;
    double costPerOunce;

public:
    Package(string sName, string sAddress, string sCity, string sState, string sZip,
            string rName, string rAddress, string rCity, string rState, string rZip,
            double w, double c) : senderName(sName), senderAddress(sAddress), senderCity(sCity),
            senderState(sState), senderZip(sZip), recipientName(rName), recipientAddress(rAddress),
            recipientCity(rCity), recipientState(rState), recipientZip(rZip), weight(w), costPerOunce(c) {
        if (weight <= 0 || costPerOunce <= 0) {
            throw invalid_argument("Weight and cost per ounce must be positive values.");
        }
    }

    virtual double calculateCost() {
        return weight * costPerOunce;
    }

    string getSenderAddress() const {
        return senderName + "\n" + senderAddress + "\n" + senderCity + ", " + senderState + " " + senderZip;
    }

    string getRecipientAddress() const {
        return recipientName + "\n" + recipientAddress + "\n" + recipientCity + ", " + recipientState + " " + recipientZip;
    }
};

class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(string sName, string sAddress, string sCity, string sState, string sZip,
                  string rName, string rAddress, string rCity, string rState, string rZip,
                  double w, double c, double f) : Package(sName, sAddress, sCity, sState, sZip,
                  rName, rAddress, rCity, rState, rZip, w, c), flatFee(f) {}

    double calculateCost() override {
        return Package::calculateCost() + flatFee;
    }
};

class OvernightPackage : public Package {
private:
    double extraCostPerOunce;

public:
    OvernightPackage(string sName, string sAddress, string sCity, string sState, string sZip,
                     string rName, string rAddress, string rCity, string rState, string rZip,
                     double w, double c, double e) : Package(sName, sAddress, sCity, sState, sZip,
                     rName, rAddress, rCity, rState, rZip, w, c), extraCostPerOunce(e) {}

    double calculateCost() override {
        return (costPerOunce + extraCostPerOunce) * weight;
    }
};

int main() //测试例子
{
    try {
        Package p("Alice", "123 Main St", "Springfield", "IL", "62704",
                  "Bob", "456 Elm St", "Springfield", "IL", "62704", 10.5, 0.5);

        TwoDayPackage tdp("Charlie", "789 Oak St", "Springfield", "IL", "62704",
                          "David", "101 Pine St", "Springfield", "IL", "62704", 8.0, 0.5, 5.0);

        OvernightPackage op("Eve", "202 Maple St", "Springfield", "IL", "62704",
                            "Frank", "303 Birch St", "Springfield", "IL", "62704", 5.0, 0.5, 0.2);

        cout << "Package cost: $" << p.calculateCost() << endl;
        cout << "TwoDayPackage cost: $" << tdp.calculateCost() << endl;
        cout << "OvernightPackage cost: $" << op.calculateCost() << endl;

        vector<Package*> packages;
        packages.push_back(&p);
        packages.push_back(&tdp);
        packages.push_back(&op);

        double totalCost = 0.0;

        for (Package* pkg : packages) {
            cout << "Sender Address:\n" << pkg->getSenderAddress() << endl;
            cout << "Recipient Address:\n" << pkg->getRecipientAddress() << endl;
            double cost = pkg->calculateCost();
            cout << "Shipping Cost: $" << cost << endl;
            totalCost += cost;
            cout << endl;
        }

        cout << "Total Shipping Cost: $" << totalCost << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}