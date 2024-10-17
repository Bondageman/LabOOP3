//#include <iostream>
//#include <string>
//#include <stdexcept>
//
//using namespace std;
//
//class ElectricityBill {
//private:
//    double pricePerKwh;
//    string date;
//    double amountPaid;
//
//public:
//    ElectricityBill(double price = -1, const string& billDate = "", double amount = -1)
//        : pricePerKwh(price), date(billDate), amountPaid(amount) {
//        if (price < 0 || amount < 0) {
//            // �� �������� �������, ���� ��'��� �������� � ������������ ���������� ��� �������� ������
//            if (!(price == -1 && amount == -1 && billDate.empty())) {
//                throw invalid_argument("Price and amount paid cannot be negative.");
//            }
//        }
//    }
//
//    // �������������� ��������� ==
//    bool operator==(const string& billDate) const {
//        return date == billDate;
//    }
//
//    // �������������� ��������� ++
//    ElectricityBill& operator++() {
//        pricePerKwh += 1;
//        amountPaid += 1;
//        return *this;
//    }
//
//    // �������������� ��������� -=
//    ElectricityBill& operator-=(double value) {
//        if (value < 0) {
//            throw invalid_argument("Value cannot be negative.");
//        }
//        pricePerKwh -= value;
//        amountPaid -= value;
//        return *this;
//    }
//
//    // ����� ��� ��������� ���������� ��� �������
//    void print() const {
//        cout << "Date: " << date << ", Price per KWh: " << pricePerKwh
//            << ", Amount paid: " << amountPaid << "\n";
//    }
//
//    // ��������, �� � ��'��� "��������"
//    bool isEmpty() const {
//        return pricePerKwh == -1 && amountPaid == -1 && date.empty();
//    }
//
//    // ������ ��� ������ � ������
//    void setPricePerKwh(double price) {
//        if (price < 0) {
//            throw invalid_argument("Price cannot be negative.");
//        }
//        pricePerKwh = price;
//    }
//
//    void setDate(const string& billDate) {
//        if (billDate.empty()) {
//            throw invalid_argument("Date cannot be empty.");
//        }
//        date = billDate;
//    }
//
//    void setAmountPaid(double amount) {
//        if (amount < 0) {
//            throw invalid_argument("Amount paid cannot be negative.");
//        }
//        amountPaid = amount;
//    }
//
//    double getPricePerKwh() const {
//        return pricePerKwh;
//    }
//
//    string getDate() const {
//        return date;
//    }
//
//    double getAmountPaid() const {
//        return amountPaid;
//    }
//};
//
//ElectricityBill findBillByDate(ElectricityBill bills[], int size, const string& searchDate) {
//    for (int i = 0; i < size; ++i) {
//        if (bills[i] == searchDate) {
//            return bills[i];
//        }
//    }
//    return -1;
//}
//
//int main() {
//    ElectricityBill bills[] = {
//        ElectricityBill(5, "2024-10-10", 228),
//        ElectricityBill(6, "2023-10-11", 1488),
//        ElectricityBill(7, "2022-10-12", 52)
//    };
//
//    ++bills[0];
//
//    bills[0] -= 2.0;
//
//    string searchDate = "2020-10-11";
//    ElectricityBill foundBill = findBillByDate(bills, 3, searchDate);
//
//    if (findBillByDate != -1) {
//        cout << "here your bill: ";
//        foundBill.print();
//    }
//    else {
//        cout << "not found: " << searchDate << endl;
//    }
//
//
//    return 0;
//}

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
    ElectricityBill(double price = -1, const string& billDate = "", double amount = -1)
        : pricePerKwh(price), date(billDate), amountPaid(amount) {
        if (price < 0 || amount < 0) {
            throw invalid_argument("Price and amount paid cannot be negative.");
        }
    }

    // �������������� ��������� ==
    bool operator==(const string& billDate) const {
        return date == billDate;
    }

    // �������������� ��������� ++
    ElectricityBill& operator++() {
        pricePerKwh += 1;
        amountPaid += 1;
        return *this;
    }

    // �������������� ��������� -=
    ElectricityBill& operator-=(double value) {
        if (value < 0) {
            throw invalid_argument("Value cannot be negative.");
        }
        pricePerKwh -= value;
        amountPaid -= value;
        return *this;
    }

    // ����� ��� ��������� ���������� ��� �������
    void print() const {
        cout << "Date: " << date << ", Price per KWh: " << pricePerKwh
            << ", Amount paid: " << amountPaid << "\n";
    }

    // ������ ��� ������ � ������
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

// ������� ��� ������ ������� ��'���� �� �����
int findBillByDate(ElectricityBill bills[], int size, const string& searchDate) {
    for (int i = 0; i < size; ++i) {
        if (bills[i] == searchDate) {
            return i + 1; 
        }
    }
    return 0; 
}

int main() {
    ElectricityBill bills[] = {
        ElectricityBill(5, "2024-10-10", 228),
        ElectricityBill(6, "2023-10-11", 1488),
        ElectricityBill(7, "2022-10-12", 52)
    };

    ++bills[0];
    bills[0] -= 2.0;

    string searchDate = "2020-10-11";
    int index = findBillByDate(bills, 3, searchDate);

    if (index != 0) {
        cout << "Here is your bill: ";
        bills[index - 1].print(); 
    }
    else {
        cout << "Not found: " << searchDate << endl;
    }

    return 0;
}
