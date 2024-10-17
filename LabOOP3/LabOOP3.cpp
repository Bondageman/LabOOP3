#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ElectricityBill {
private:
    double pricePerKwh;
    string date;
    double amountPaid;

public:
    ElectricityBill(double price, const string& billDate, double amount)
        : pricePerKwh(price), date(billDate), amountPaid(amount) {
        if (price < 0 || amount < 0) {
            throw invalid_argument("Price and amount paid cannot be negative.");
        }
    }

    bool operator==(const string& billDate) const {
        return date == billDate;
    }

    ElectricityBill& operator++() {
        pricePerKwh += 1;
        amountPaid += 1;
        return *this;
    }

    ElectricityBill& operator-=(double value) {
        if (value < 0) {
            throw invalid_argument("Value cannot be negative.");
        }
        pricePerKwh -= value;
        amountPaid -= value;
        return *this;
    }

    void print() const {
        cout << "Date: " << date << ", Price per KWh: " << pricePerKwh
            << ", Amount paid: " << amountPaid << "\n";
    }

    void setPricePerKwh(double price) {
        if (price < 0) {
            throw invalid_argument("Price cannot be negative.");
        }
        pricePerKwh = price;
    }

    void setDate(const string& billDate) {
        if (billDate.empty()) {
            throw invalid_argument("Date cannot be empty.");
        }
        date = billDate;
    }

    void setAmountPaid(double amount) {
        if (amount < 0) {
            throw invalid_argument("Amount paid cannot be negative.");
        }
        amountPaid = amount;
    }

    double getPricePerKwh() const {
        return pricePerKwh;
    }

    string getDate() const {
        return date;
    }

    double getAmountPaid() const {
        return amountPaid;
    }
};

int findBillByDate(ElectricityBill bills[], int size, const string& searchDate) {
    for (int i = 0; i < size; ++i) {
        if (bills[i] == searchDate) {
            return i + 1; 
        }
    }
    return 0; 
}

int main() {
    try {
        ElectricityBill bills[] = {
            ElectricityBill(5, "2024-10-10", 228),
            ElectricityBill(6, "2023-10-11", 1488),
            ElectricityBill(7, "2022-10-12", 52)
        };

        ++bills[0];
        bills[0] -= 2.0;

        string searchDate = "2023-10-11";
        int index = findBillByDate(bills, 3, searchDate);

        if (index != 0) {
            cout << "Here is your bill: ";
            bills[index - 1].print();
        }
        else {
            cout << "Not found: " << searchDate << endl;
        }
    }

    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;  
    }

    return 0;
}

