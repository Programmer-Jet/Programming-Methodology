    #include <iostream>
    #include <string>
    using namespace std;

    class Package // Base Class
    {
    private:
    	string name, city, state, sender, recipient;
        int zip;
        string address;
        float weight;  // in ounce
        double cost;  // per ounce

    public:
        void setName(string name);
        void setCity(string city);
        void setState(string state);
        void setZip(int zip);
        void setAddress(string address);
        void setSender(string sender);
        void setRecipient(string recipient);
        string getName(){return name;}
        string getCity(){return city;}
        string getState(){return state;}
    	int getZip(){return zip;}
    	string getAddress(){return address;}
    	string getSender(){return sender;}
    	string getRecipient(){return recipient;}

    double calculateCost(float weight,double costPerOunce) //function that calculate the cost z
    {
    	double totalCost = weight * costPerOunce; ;  //total cost = weight*cost per ounce
    	cout<< "The Base Cost = " << totalCost << endl<<endl;
        return totalCost;
    }
    }; // end class Package

    void Package::setName(string n){name = n;}
    void Package::setCity(string c){city = c;}
    void Package::setState(string s){state = s;}
    void Package::setZip (int zp){zip = zp;}
    void Package::setAddress(string adr){address = adr;}
    void Package::setSender(string sen){sender = sen;}
    void Package::setRecipient(string rec){recipient = rec;}

    class TwoDayPackage: public Package // derived class TwoDayPackage, base class Package
    {
    private:
    	double flatFee;
    public:
    	double calcShippingCost(float weight, double costPerOunce, double flatFee)
    		/* function that calculate shipping cost by adding the flat fee to the weight-based cost
    		calculated by base class Package’s calculateCost function*/
    	{
    		double shippingCost; //shipping cost of Two day Package class
    		shippingCost = calculateCost(weight,costPerOunce) + flatFee;
    		cout<< "The TwoDayPackage Cost = " << shippingCost << endl;
    		return shippingCost;
    	}
    }; // end TwoDayPackage

    class OvernightPackage: public Package //derived class that adds the additional fee per ounce
    {
    public:
    	double calcCostOvernight(float weight,double costPerOunce,double additionalCost )
    	{
    		double shippingCost; //shipping cost of overnight class
    		shippingCost = calculateCost(weight, costPerOunce)+(additionalCost * weight);
    		cout << "The OvernightPackage Cost = " << shippingCost << endl;
    		return shippingCost;
    	}
    private:
    	double overnightCost; //per ounce
    }; // end class OvernightPackage

    int main()
    {
    	Package base;
        TwoDayPackage twoday;
        OvernightPackage overnight;
        base.calculateCost(10,10); //Calculate Base Cost
        twoday.calcShippingCost(10,10,10); //Calculate Two Day Cost
        overnight.calcCostOvernight(10,10,10); //Calculate Over Night Cost
    	return 0;
    } // end main
