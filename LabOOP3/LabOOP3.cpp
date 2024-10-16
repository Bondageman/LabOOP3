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
    // �����������
    ElectricityBill(double price, const string& billDate, double amount)
        : pricePerKwh(price), date(billDate), amountPaid(amount) {
        if (price < 0 || amount < 0) {
            throw invalid_argument("Price and amount paid cannot be negative.");
        }
    }

    // �������������� ��������� ++ (���������)
    ElectricityBill& operator++() {
        pricePerKwh += 1;
        amountPaid += 1;
        return *this;
    }

    // �������������� ��������� -= ��� ��������� ���������
    ElectricityBill& operator-=(double value) {
        if (value < 0) {
            throw invalid_argument("Value cannot be negative.");
        }
        pricePerKwh -= value;
        amountPaid -= value;
        return *this;
    }

    // �������������� ������ ��� ������ �� �����
    bool findByDate(const string& searchDate) const {
        return date == searchDate;
    }

    // �������
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

    // �������
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

int main() {
    try {
        // ��������� ��'����
        ElectricityBill bill(5, "2024-10-10", 100);

        // ������ ��������� ++
        ++bill;

        // ��������� ������� �� ��������� -=
        bill -= 2.0;

        // �������� ����
        if (bill.findByDate("2024-10-10")) {
            cout << "Bill found for the date 2024-10-10.\n";
        }

        // ��������� � ����������� �����
        cout << "Price per KWh: " << bill.getPricePerKwh() << "\n";
        cout << "Amount paid: " << bill.getAmountPaid() << "\n";

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
