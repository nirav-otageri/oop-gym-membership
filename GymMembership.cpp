#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Member
{
protected:
    int id{}, age{};
    string name, mobile;

public:
    void getDetails()
    {
        cout << "Enter Member ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Mobile Number: ";
        cin >> mobile;
    }

    void displayDetails() const
    {
        cout << "\nMember ID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nMobile: " << mobile;
    }

    void writeDetails(ofstream &file) const
    {
        file << "Member ID: " << id << endl;
        file << "Name: " << name << endl;
        file << "Age: " << age << endl;
        file << "Mobile: " << mobile << endl;
    }
};

class Membership : public Member
{
    int duration{}, fees{};

public:
    int getId() const { return id; }
    int getAge() const { return age; }
    const string &getName() const { return name; }
    int getDuration() const { return duration; }
    int getFees() const { return fees; }
    bool getMembership()
    {
        int choice;

        cout << "\n\nSelect Membership Plan";
        cout << "\n1. 1 Month - ₹1,000";
        cout << "\n2. 3 Months - ₹2,500";
        cout << "\n3. 6 Months - ₹4,500";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            duration = 1;
            fees = 1000;
            return true;
        case 2:
            duration = 3;
            fees = 2500;
            return true;
        case 3:
            duration = 6;
            fees = 4500;
            return true;
        default:
            cout << "Invalid plan!\n";
            return false;
        }
    }

    void displayMembership() const
    {
        displayDetails();
        cout << "\nMembership Duration: " << duration << " Months";
        cout << "\nTotal Fees: ₹" << fees << "\n";
    }

    void saveToFile(ofstream &file) const
    {
        writeDetails(file);
        file << "Duration: " << duration << " Months" << endl;
        file << "Fees: ₹" << fees << endl;
        file << "----------------------" << endl;
    }
};

int main()
{
    vector<Membership> memberships;
    int choice;

    cout << "===== GYM MEMBERSHIP SYSTEM =====\n";

    do
    {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Add Membership";
        cout << "\n2. Display Memberships";
        cout << "\n3. Save to file";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Membership member;
            member.getDetails();

            if (member.getMembership())
            {
                memberships.push_back(member);
                cout << "\nMembership added successfully!\n";
            }
            break;
        }
        case 2:
            if (memberships.empty())
            {
                cout << "\nNo memberships to display.\n";
            }
            else
            {
                int totalValue = 0;

                cout << "\n------------------------------------------------------------\n";
                cout << "                     MEMBERSHIP DETAILS\n";
                cout << "------------------------------------------------------------\n";
                cout << left
                     << setw(12) << "Member ID"
                     << setw(15) << "Name"
                     << setw(8) << "Age"
                     << setw(13) << "Duration"
                     << "Fees (₹)\n";
                cout << "------------------------------------------------------------\n";

                for (const Membership &member : memberships)
                {
                    cout << left
                         << setw(12) << member.getId()
                         << setw(15) << member.getName()
                         << setw(8) << member.getAge()
                         << setw(13) << (to_string(member.getDuration()) + " months")
                         << member.getFees() << '\n';

                    totalValue += member.getFees();
                }

                cout << "------------------------------------------------------------\n";
                cout << "TOTAL MEMBERSHIP VALUE: ₹" << totalValue << '\n';
                cout << "------------------------------------------------------------\n";
            }
            break;
        case 3:
        {
            ofstream file("members.txt", ios::app);

            if (!file)
            {
                cout << "\nError: Could not open members.txt.\n";
                break;
            }

            for (const Membership &member : memberships)
            {
                member.saveToFile(file);
            }

            cout << "\nMemberships saved to file successfully!\n";
            break;
        }
        case 4:
            cout << "\nThankyou for using the system.\n";
            break;
        default:
            cout << "\nError: Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}