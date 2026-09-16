#include <iostream>
#include <string>
using namespace std;

class Package 
{
protected:
    string senderName, senderAddress, senderCity, senderState, senderZip;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZip;
    double weight;
    double costPerOunce; 

public:
    Package(const string& sName, const string& sAddress, const string& sCity, const string& sState, const string& sZip,
            const string& rName, const string& rAddress, const string& rCity, const string& rState, const string& rZip,
            double w, double c)
        : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZip(sZip),
          recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZip(rZip),
          weight(w), costPerOunce(c) 
    {
        if(weight<=0||costPerOunce<=0) 
        {
            throw invalid_argument("Weight and cost per ounce must be positive values!!!");
        }
    }

    virtual double calculateCost() const 
    {
        return weight * costPerOunce;
    }

    void display() const 
    {
        cout << "Sender: " << senderName << ", " << senderAddress << ", " << senderCity << ", " << senderState << ", " << senderZip << endl;
        cout << "Recipient: " << recipientName << ", " << recipientAddress << ", " << recipientCity << ", " << recipientState << ", " << recipientZip << endl;
        cout << "Weight: " << weight << " oz" << endl;
        cout << "Cost per ounce: $" << costPerOunce << endl;
    }
};


class TwoDayPackage : public Package 
{
protected:
    double flatFee;

public:
    TwoDayPackage(const string& sName, const string& sAddress, const string& sCity, const string& sState, const string& sZip,
                  const string& rName, const string& rAddress, const string& rCity, const string& rState, const string& rZip,
                  double w, double c, double f)
        : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, c), flatFee(f) {}

    virtual double calculateCost() const override 
    {
        return Package::calculateCost() + flatFee;
    }

    void display() const 
    {
        Package::display();
        cout << "Flat fee: $" << flatFee << endl;
    }
};


class OvernightPackage : public Package 
{
protected:
    double extraCostPerOunce;

public:
    OvernightPackage(const string& sName, const string& sAddress, const string& sCity, const string& sState, const string& sZip,
                     const string& rName, const string& rAddress, const string& rCity, const string& rState, const string& rZip,
                     double w, double c, double e)
        : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, c), extraCostPerOunce(e) {}

    virtual double calculateCost() const override 
    {
        return weight * (costPerOunce + extraCostPerOunce);
    }


    void display() const 
    {
        Package::display();
        cout << "Extra cost per ounce: $" << extraCostPerOunce << endl;
    }
};


int main() 
{
    Package package("John Doe", "123 Main St", "Anytown", "CA", "12345","Jane Smith", "456 Elm St", "Othertown", "NY", "67890",10.5, 0.5);

    TwoDayPackage twoDayPackage("Alice Johnson", "789 Oak St", "Sometown", "TX", "54321","Bob Brown", "321 Pine St", "Downtown", "FL", "11223",8.0, 0.6, 5.0);

    OvernightPackage overnightPackage("Charlie Davis", "987 Maple St", "Uptown", "IL", "98765", "Diana White", "654 Birch St", "Downtown", "CO", "54321",5.5, 0.7, 1.0);

    cout << "Package Cost: $" << package.calculateCost() << endl;
    package.display();
    cout << endl;

    cout << "Two Day Package Cost: $" << twoDayPackage.calculateCost() << endl;
    twoDayPackage.display();
    cout << endl;

    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;
    overnightPackage.display();
    cout << endl;
    return 0;
}