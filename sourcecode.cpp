#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
#include <chrono>
#include <sstream>
#include<algorithm>
#include<cctype>

using namespace std;

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_WHITE "\033[97m"
#define BRIGHT_PURPLE "\033[95m"

vector<string>userdata;
// Global variables to track sales data
struct SalesData {
    string itemName;
    double price;
    string description;
    int quantitySold;
    double totalSales;
};

vector<SalesData> salesRecords;
double totalDailySales = 0.0;

void clearInputBuffer();
void luckynumsystem();
void drawLine();
void displayTermsAndConditions();
void displayPrizeBoard(const string& firstPrize, const string& secondPrize, const string& thirdPrize);
int completeluckydraw();
bool isValidNumber(const string& str);
void displayWelcome();
void displayoption();
string getCurrentDateTime();
void displayMenu();
bool loginUser(string& userInfo);
void placeOrder();
void generateSalesReport();
void generateProfitReport();
void printQRCode();
void printReceipt(const vector<string>& itemsPurchased, const vector<int>& quantities, const vector<double>& prices, double subtotal, double tax, double totalWithTax, char paymentMethod, double amountPaid, double change);
void initializeSalesRecords(const string items[], const double prices[], const string descriptions[], int numItems);
void updateSalesData(const vector<string>& itemNames, const vector<int>& quantities);
void displayCurrentItems();
void changeItemAndPrice();
void staffaccess();

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void drawLine() {
    cout << CYAN << setw(50) << setfill('=') << ">" << RESET << endl;

    cout << setfill(' ') << setw(0);

}

void displayTermsAndConditions() {
    drawLine();
    cout << CYAN << "==> " << YELLOW << setw(26) << "20th Anniversary Tournament Giveaway" << CYAN << " <==" << RESET << endl;
    drawLine();

    cout << setw(50) << setfill(' ') << " " << endl;
    cout << GREEN << "Enter your lucky number to draw a prize!" << RESET << endl;

    cout << setw(50) << setfill(' ') << " " << endl;
    cout << GREEN << "If you enter a number that is not desired," << RESET << endl;
    cout << GREEN << "please enter any other than number to restart." << RESET << endl;

    cout << setw(50) << setfill(' ') << " " << endl;
    cout << GREEN << "Enter a number between 50 to 150 to stand a chance" << RESET << endl;
    cout << GREEN << "to win the limited edition Holographic Smartphone by ROG" << RESET << endl;
    cout << GREEN << "valued at RM8999." << RESET << endl;

    cout << setw(50) << setfill(' ') << " " << endl;
    cout << GREEN << "Second prize: enter a number between 0 to 50." << RESET << endl;
    cout << GREEN << "Third prize: enter a number between 0 to 20." << RESET << endl;
    cout << GREEN << "Once you won the prize please proceed to counter 2 to redeem the prize" << RESET << endl;

    cout << setw(50) << setfill(' ') << " " << endl;
    drawLine();
}
void displayPrizeBoard(const string& firstPrize, const string& secondPrize, const string& thirdPrize) {
    drawLine();
    cout << CYAN << "==> " << YELLOW << setw(26) << "TOURNAMENT PRIZE BOARD" << CYAN << " <==" << RESET << endl;
    drawLine();

    cout << setw(50) << setfill(' ') << " " << endl;
    cout << CYAN << "==> " << GREEN << "First Prize: " << BLUE << firstPrize << CYAN << " <==" << RESET << endl;

    cout << setw(50) << setfill(' ') << " " << endl;
    cout << CYAN << "==> " << GREEN << "Second Prize: " << BLUE << secondPrize << CYAN << " <==" << RESET << endl;

    cout << setw(50) << setfill(' ') << " " << endl;
    cout << CYAN << "==> " << GREEN << "Third Prize: " << BLUE << thirdPrize << CYAN << " <==" << RESET << endl;

    drawLine();
}
int completeluckydraw() {

    string firstPrize = "Holographic Smartphone";
    string secondPrize = "Quantum Bluetooth Speaker";
    string thirdPrize = "Neon Fitness Band";
    displayTermsAndConditions();

    // Generate random prize numbers first
    int firstprize;
    int secondprize;
    int thirdprize;
    // Seeding the random number generator
    srand(time(NULL));

    firstprize = rand() % 101 + 50; // Random number between 50 to 150
    secondprize = rand() % 50 + 0;
    thirdprize = rand() % 20 + 0;

    // Ensure unique prizes
    while (secondprize == firstprize) {
        secondprize = rand() % 50 + 0;
    }
    while (thirdprize == secondprize || thirdprize == firstprize) {
        thirdprize = rand() % 20 + 0;
    }

    // Display the sci-fi themed prize board
    displayPrizeBoard(firstPrize, secondPrize, thirdPrize);


    int num1, num2, num3;
    while (true) {
        cout << "Enter 3 lucky numbers to win a prize: " << endl;

        // First number
        cout << "First number: ";
        cin >> num1;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        // Second number
        cout << "Second number: ";
        cin >> num2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        // Third number
        cout << "Third number: ";
        cin >> num3;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        // If all inputs are valid, break the loop
        break;
    }

    cout << "You entered valid numbers: " << num1 << ", " << num2 << ", " << num3 << endl;

    // Check for first number
    if (num1 == firstprize)
        cout << num1 << "WHAT KIND OF LUCK IS THIS you just won the first prize! Please redeem it at counter1" << endl;
    else if (num1 == secondprize)
        cout << num1 << " won the second prize!" << endl;
    else if (num1 == thirdprize)
        cout << num1 << " won the third prize!" << endl;
    else
        cout << "You did not win with the number " << num1 << "." << endl;

    // Check for second number
    if (num2 == firstprize)
        cout << num2 << "CONGRAT won the first prize! Please redeem it at counter1" << endl;
    else if (num2 == secondprize)
        cout << num2 << " won the second prize!" << endl;
    else if (num2 == thirdprize)
        cout << num2 << " won the third prize!" << endl;
    else
        cout << "You did not win with the number " << num2 << "." << endl;

    // Check for third number
    if (num3 == firstprize)
        cout << num3 << "YOU ARE THE CHOSEN ONE you won the first prize! Please redeem it at counter1" << endl;
    else if (num3 == secondprize)
        cout << num3 << " won the second prize!" << endl;
    else if (num3 == thirdprize)
        cout << num3 << " won the third prize!" << endl;
    else
        cout << "Better lucky next time with  " << num3 << "." << endl;
    bool anotherCustomer = true;
    char nextCustomer;
    while (true) {
        cout << "\nIs there another customer? (Y/N): ";
        cin >> nextCustomer;
        nextCustomer = toupper(nextCustomer);

        if (nextCustomer == 'Y') {
            break; // Continue the loop for the next customer
        }
        else if (nextCustomer == 'N') {
            anotherCustomer = false;
            cout << "Thank you for using the system. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid input. Please enter 'Y' for Yes or 'N' for No." << endl;
        }

    }
    return 0;
}

// Function to check if a string represents a valid integer
bool isValidNumber(const string& str) {
    if (str.empty()) return false;
    for (char const& ch : str) {
        if (!isdigit(ch)) return false;
    }
    return true;
}


void displayWelcome() {
    cout << BOLD << CYAN << "                                                 ***************************************************************" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *" << RESET << "                                                             " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    " << BOLD << CYAN << " *" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDCYAN << "@                                                 @    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDCYAN << "@    " << BOLDYELLOW << "W E L C O M E   T O  {P S P}   E V E N T" << BOLDCYAN << "     @    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDCYAN << "@                                                 @    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    " << BOLD << CYAN << " *" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *                                                             " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "###################################################    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "#                                                 #    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "#                " << BOLDYELLOW << "PPPPPPPPPP" << BOLDRED << "                       #    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "#                " << BOLDCYAN << "P        P" << BOLDRED << "                       #    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "#                " << BOLDCYAN << "P        P" << BOLDRED << "                       #    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "#                " << BOLDYELLOW << "PPPPPPPPP" << BOLDRED << "                        #    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "#                " << BOLDCYAN << "P                                " << BOLDRED << "#    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "#                " << BOLDCYAN << "P                                " << BOLDRED << "#    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *      " << BOLDRED << "###################################################    " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 *                                                             " << BOLD << CYAN << "*" << RESET << endl;
    cout << BOLD << CYAN << "                                                 ***************************************************************" << RESET << endl << endl << endl;
}

// Function to display options
void displayoption() {
    cout << "                                                 " << "***************************************************************" << endl;
    cout << "                                                 " << "*                                                             *" << endl;
    cout << "                                                 " << "*             PLEASE CHOOSE AN OPTION                         *" << endl;
    cout << "                                                 " << "*      +-----------------------------------+                  *" << endl;
    cout << "                                                 " << "*      |   1. ORDER                        |                  *" << endl;
    cout << "                                                 " << "*      |   2. SALES REPORT                 |                  *" << endl;
    cout << "                                                 " << "*      |   3. EXIT                         |                  *" << endl;
    cout << "                                                 " << "*      |   4. STAFF ONLY                   |                  *" << endl;
    cout << "                                                 " << "*      +-----------------------------------+                  *" << endl;
    cout << "                                                 " << "*                                                             *" << endl;
    cout << "                                                 " << "***************************************************************" << endl << endl << endl;
}

// Function to print a simple QR code pattern
void printQRCode() {
    vector<string> qrCode = {
        "### # ##  #   # ###  #   # ###  # ## # #  #",
        "#  # #  #  # # #  # # # # # #  # #   #  # ##",
        "# ## ## # ## #  # # ## #   ##  # # #  #   #",
        "# ## ## # # #  # # # ## #  ## # ## ## # # ##",
        "#  # #  # ## # # # ## #  #   # ## #  #   #  ",
        "###  # ## ##  # #   # ## ##  ##  #   ## ##  ",
        "### ## # ##   #   # # # ## ##   # ## #  ## ##",
        "## #  ## ## ##   # ## ## ##   # #  ## #  ## ",
        "# # # # # ##   ##  #  # ##  ##   #  #   ## ",
        "# ## ## #   ##  ##  # # ## ##   ##  ## ##  #",
        "# ##   #   ##  # ##  ##   ##  #   #   # ## ##",
        "# ## # #  #   # ##  # #  ## ##  ##  ## ##   ",
        "###  # ## ## ##   # ## #  # ## ##   ##  ##  ",
        "# #  ##  #  ##   ##   #   ##  #  #  ##  # ##",
        "#  # # #  ## #  ##  ##   # ## # ##   ##  # ##",
        "##   # ##  #  # #  # ##  ##  ##   # #  ## ##",
        "##  ##  #  ## ##  ## # ## ##   ##  ##   ##  ",
        "### #  #   # ## # ## ##  #  #  #   ##  ##   ",
        "####  ## ##   #  ##  # # # # ##   ##  ## #  ",
        "###   # #  ##   # #  # ##   ## # # #  #  ##  "
    };

    for (const auto& line : qrCode) {
        cout << "                                                 " << line << endl;
    }
}


// Function to get the current date and time as a string
string getCurrentDateTime() {
    using namespace std::chrono;
    auto now = system_clock::now();
    auto now_c = system_clock::to_time_t(now);

    // Convert time_t to tm struct for local time
    tm local_tm;
#ifdef _WIN32
    localtime_s(&local_tm, &now_c); // Windows-specific
#else
    localtime_r(&now_c, &local_tm); // POSIX-specific
#endif

    // Use a stringstream to format the date and time
    stringstream ss;
    ss << put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Function to display the menu of items
void displayMenu() {
    const int column1Width = 1;
    const int column2Width = 22;
    const int column3Width = 15;
    const int column4Width = 40;

    cout << "                                                 " << "+----+-------------------------+-----------------+-----------------------------------------------------+" << endl;
    cout << "                                                 " << "| No | Item                    | Price (RM)      | Description                                         |" << endl;
    cout << "                                                 " << "+----+-------------------------+-----------------+-----------------------------------------------------+" << endl;

    for (size_t i = 0; i < salesRecords.size(); ++i) {
        cout << "                                                 "
            << "|  " << setw(column1Width) << i + 1
            << " |  " << setw(column2Width) << left << salesRecords[i].itemName
            << " |  RM" << setw(column3Width - 3) << right << fixed << setprecision(2) << salesRecords[i].price
            << " |  " << setw(column4Width - 5) << left << salesRecords[i].description
            << " | " << endl;
    }

    cout << "                                                 " << "+----+-------------------------+-----------------+-----------------------------------------------------+" << endl;
}


// Function to handle user login
bool loginUser(string& userInfo) {
    string input;
    char choice;


    cout << "Would you like to log in? (Y/N): ";
    cin >> choice;
    choice = toupper(choice);


    while (choice == 'N') {
        cout << "Skipping login.\n";
        return true;
    }

    while (choice != 'Y') {
        cout << "Invalid input. Please enter 'Y' to log in or 'N' to skip: ";
        cin >> choice;
        choice = toupper(choice);

        while (choice == 'N') {
            cout << "Skipping login.\n";
            return true;
        }

    }


    while (true) {
        cout << "Enter your phone number or Gmail address(\"Enter (Q) to quit\"): ";
        cin.ignore();
        getline(cin, input);

        if (input == "Q" || input == "q") {
            cout << "You chose to quit. Exiting..." << endl;
            return false;  // Return false to indicate quitting
        }

        cout << "You entered: " << input << endl;
        cout << "Is this information correct? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'Y') {
            userInfo = input;
            userdata.push_back(userInfo);
            return true;
        }
        else if (choice == 'N') {
            cout << "Please re-enter your information.\n";
        }
        else {
            cout << "Invalid input. Please enter 'Y' or 'N'.\n";
        }
    }
}


// Function to check if a given amount can be made with available denominations
bool canMakeChange(double amount) {
    // Available denominations in cents
    const vector<int> denominations = { 5, 10, 20, 50 };

    // Convert the amount to cents
    int remaining = static_cast<int>(round(amount * 100));

    // Use dynamic programming to determine if change can be made
    vector<bool> canMake(remaining + 1, false);
    canMake[0] = true;

    for (int i = 0; i <= remaining; ++i) {
        if (canMake[i]) {
            for (int denom : denominations) {
                if (i + denom <= remaining) {
                    canMake[i + denom] = true;
                }
            }
        }
    }

    return canMake[remaining];
}
void placeOrder() {
    string userInfo;
    if (!loginUser(userInfo)) {
        cout << "Failed to log in. Returning to main menu...\n";
        return;
    }

    const double TAX_RATE = 0.06;
    const int numItems = salesRecords.size();
    char paymentMethod;
    bool anotherCustomer = true;

    while (anotherCustomer) {
        double total = 0.0;
        string input;
        int choice;
        int quantity;
        bool validSelection = false;
        vector<string> itemsPurchased;
        vector<int> quantities;
        vector<double> prices;

        displayMenu();

        while (true) {
            cout << "Enter the number of the item you want to buy (0 to finish, 'Q' to quit): ";
            cin >> input;

            if (cin.fail()) {
                clearInputBuffer();
                cout << "Invalid input. Please enter a number or 'Q' to quit." << endl;
                continue;
            }

            if (input == "q" || input == "Q") {
                cout << "Returning to main menu...\n";
                return;
            }

            try {
                choice = stoi(input);
            }
            catch (const invalid_argument&) {
                cout << "Invalid input. Please enter a number or 'Q' to quit." << endl;
                continue;
            }

            if (choice == 0) {
                break;
            }
            else if (choice >= 1 && choice <= numItems) {
                cout << "Enter the quantity of " << salesRecords[choice - 1].itemName << " ('Q' to quit): ";
                cin >> input;

                if (input == "q" || input == "Q") {
                    cout << "Returning to main menu...\n";
                    return;
                }

                try {
                    quantity = stoi(input);
                }
                catch (const invalid_argument&) {
                    cout << "Invalid quantity. Please enter a number or 'Q' to quit." << endl;
                    continue;
                }

                if (quantity <= 0 || quantity > 10) {
                    cout << "Invalid quantity. Please enter a number between 1 and 10." << endl;
                    continue;
                }

                total += salesRecords[choice - 1].price * quantity;
                validSelection = true;

                itemsPurchased.push_back(salesRecords[choice - 1].itemName);
                quantities.push_back(quantity);
                prices.push_back(salesRecords[choice - 1].price);
            }
            else {
                cout << "Invalid choice. Please enter a number between 1 and " << numItems << "." << endl;
            }
        }

        if (!validSelection) {
            cout << "You did not select any items." << endl;
            continue;
        }

        double taxAmount = total * TAX_RATE;
        double totalWithTax = total + taxAmount;

        cout << fixed << setprecision(2);
        cout << "Subtotal: RM" << setw(7) << total << endl;
        cout << "Tax (6%): RM" << setw(7) << taxAmount << endl;
        cout << "Total amount including tax: RM" << setw(7) << totalWithTax << endl;

        while (true) {
            cout << "Select your payment method ('Q' to quit):\n"
                << "A - Visa\n"
                << "B - DuitNow\n"
                << "C - Cash\n"
                << "Enter your choice: ";
            cin >> input;

            if (input == "q" || input == "Q") {
                cout << "Returning to main menu...\n";
                return;
            }

            paymentMethod = toupper(input[0]);

            if (paymentMethod == 'A' || paymentMethod == 'B' || paymentMethod == 'C') {
                break;
            }
            else {
                cout << "Invalid payment method. Please choose A, B, C, or 'Q' to quit." << endl;
            }
        }

        double amountPaid = 0.0;
        double change = 0.0;

        if (paymentMethod == 'A') {
            cout << "Payment successful using Visa!" << endl;
            amountPaid = totalWithTax;
        }
        else if (paymentMethod == 'B') {
            cout << "Please scan the QR code to complete the payment." << endl;
            printQRCode();
            cout << "Press Enter once you have completed the payment (or 'Q' to quit): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, input);
            if (input == "q" || input == "Q") {
                cout << "Returning to main menu...\n";
                return;
            }
            cout << "Payment successful using DuitNow!" << endl;
            amountPaid = totalWithTax;
        }
        else if (paymentMethod == 'C') {

            while (true) {

                cout << "Enter the amount you are paying (or 'Q' to quit): RM";
                cin >> input;

                if (input == "q" || input == "Q") {
                    cout << "Returning to main menu...\n";
                    return;
                }

                try {
                    amountPaid = stod(input);
                }
                catch (const invalid_argument&) {
                    cout << "Invalid input. Please enter a valid amount or 'Q' to quit." << endl;
                    continue;
                }

                if (amountPaid < totalWithTax) {
                    cout << "Insufficient amount. Please pay at least RM" << fixed << setprecision(2) << totalWithTax << "." << endl;
                    continue;
                }


                if (amountPaid > totalWithTax + 150.00) {
                    cout << "Amount exceeds the maximum limit of RM" << fixed << setprecision(2) << totalWithTax + 150.00 << ". Please enter a valid amount." << endl;
                    continue;
                }

                if (amountPaid < totalWithTax) {
                    cout << "Insufficient amount. Please pay at least RM" << fixed << setprecision(2) << totalWithTax << "." << endl;
                    continue;
                }

                double change = amountPaid - totalWithTax;

                // Check if the total amount and change amount can be given using available denominations
                if (amountPaid == static_cast<int>(round(amountPaid * 100)) / 100.0 && !canMakeChange(change)) {
                    cout << "Invalid amount. Change can only be given in available denominations (5, 10, 20, 50 cents)." << endl;
                    continue;
                }

                cout << "Payment successful!" << endl;
                break;
            }
        }

        printReceipt(itemsPurchased, quantities, prices, total, taxAmount, totalWithTax, paymentMethod, amountPaid, change);
        char luck;//from here mades the cout and cin ambiguous error

        while (true) {
            cout << "Proceed to lucky draw(Y/N): ";
            cin >> luck;
            luck = toupper(luck);

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
                continue;
            }

            if (luck == 'Y') {
                cout << "Proceeding to lucky draw" << endl;
                break;
            }
            else if (luck == 'N') {
                cout << "Exiting the program" << endl;
                return;
            }
            else {
                cout << "INVALID INPUT" << endl;
                continue;
            }
        }//to here why isit like that please help 
        completeluckydraw();

        char continueChoice;
        cout << "Do you want to process another customer? (Y/N): ";
        cin >> continueChoice;
        anotherCustomer = (toupper(continueChoice) == 'Y');
    }
}


// Fixed generateSalesReport() function
void generateSalesReport() {
    cout << "============================== Daily Sales Report ==============================" << endl;
    cout << "Total Sales for Today: RM" << fixed << setprecision(2) << totalDailySales << endl;
    cout << "================================================================================" << endl;

    cout << "|" << setw(25) << left << "Item"
        << "|" << setw(15) << right << "Tickets Sold"
        << "|" << setw(15) << right << "Total Sales"
        << "|" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    for (const auto& item : salesRecords) {
        cout << "|" << setw(25) << left << item.itemName
            << "|" << setw(15) << right << item.quantitySold
            << "|" << setw(15) << right << fixed << setprecision(2) << item.totalSales
            << "|" << endl;
    }

    cout << "================================================================================" << endl << endl;
}
void generateProfitReport() {
    double profit = 0.0, totalCost = 0.0;
    int i;
    vector<string> type
    {
        "Venue" ,
        "Equipment" ,
        "Staff" ,
        "Marketing"
    };

    vector<double> cost
    { 10000,50000,50000,30000 };

    cout << "================================ Profit Report =================================" << endl;
    cout << "|           Type of cost               |             Total cost (RM)           |" << endl;
    cout << "================================================================================" << endl;

    for (i = 0; i < type.capacity(); ++i) {
        totalCost += cost[i];
        profit = totalDailySales - totalCost;

        cout << "|" << setw(19) << type[i] << setw(20) << "|" << setw(22) << showpoint << fixed << setprecision(2) << cost[i] << setw(18) << "|" << endl;

    }
    cout << "================================================================================" << endl;
    cout << "|Total sales for Today:" << setw(20) << "RM" << setw(19) << fixed << setprecision(2) << totalDailySales << setw(18) << "|" << endl;
    cout << "|Total cost for Today:" << setw(21) << "RM" << setw(19) << fixed << setprecision(2) << totalCost << setw(18) << "|" << endl;
    cout << "|Total Profit for Today:" << setw(19) << "RM" << setw(19) << fixed << setprecision(2) << profit << setw(18) << "|" << endl;
    cout << "================================================================================" << endl << endl << endl;
}
void printReceipt(const vector<string>& itemsPurchased, const vector<int>& quantities, const vector<double>& prices, double subtotal, double tax, double totalWithTax, char paymentMethod, double amountPaid, double change) {
    const int ITEM_WIDTH = 20;
    const int QUANTITY_WIDTH = 8;
    const int PRICE_WIDTH = 10;

    cout << "                                                 " << "+-------------------------------------------------+" << endl;
    cout << "                                                 " << "|                  PSP Event                      |" << endl;
    cout << "                                                 " << "|            Email: pspevent123@gmail.com         |" << endl;
    cout << "                                                 " << "|         Date & Time: " << getCurrentDateTime() << "        |" << endl;
    cout << "                                                 " << "+----+----------------------+----------+----------+" << endl;
    cout << "                                                 " << "| No | Item                 | Quantity | Price    |" << endl;
    cout << "                                                 " << "+----+----------------------+----------+----------+" << endl;

    for (size_t i = 0; i < itemsPurchased.size(); ++i) {
        cout << "                                                 "
            << "| " << setw(1) << i + 1
            << "  | " << setw(ITEM_WIDTH) << left << itemsPurchased[i]
            << " | " << setw(QUANTITY_WIDTH) << right << quantities[i]
            << " | RM" << setw(PRICE_WIDTH - 3) << fixed << setprecision(2) << prices[i] * quantities[i]
            << "|" << endl;
    }

    cout << "                                                 " << "+----+----------------------+----------+----------+" << endl;
    cout << "                                                 " << "| Subtotal:              RM" << setw(22) << fixed << setprecision(2) << subtotal << " |" << endl;
    cout << "                                                 " << "| Tax (6%):              RM" << setw(22) << fixed << setprecision(2) << tax << " |" << endl;
    cout << "                                                 " << "| Total amount:          RM" << setw(22) << fixed << setprecision(2) << totalWithTax << " |" << endl;
    cout << "                                                 " << "+-------------------------------------------------+" << endl;
    cout << "                                                 " << "| Payment Method:       " << setw(25) << (paymentMethod == 'A' ? "Visa" : paymentMethod == 'B' ? "DuitNow" : "Cash") << " |" << endl;

    if (paymentMethod == 'C') { // Cash payment
        cout << "                                                 " << "| Amount Paid:           RM" << setw(22) << fixed << setprecision(2) << amountPaid << " |" << endl;
        if (change > 0.0) {
            cout << "                                                 " << "| Change:                RM" << setw(22) << fixed << setprecision(2) << change << " |" << endl;
        }
    }

    cout << "                                                 " << "+-------------------------------------------------+" << endl;

    // Update sales data
    for (size_t i = 0; i < itemsPurchased.size(); ++i) {
        updateSalesData(itemsPurchased, quantities);
    }
}



void initializeSalesRecords(const string items[], const double prices[], const string descriptions[], int numItems) {
    for (int i = 0; i < numItems; ++i) {
        salesRecords.push_back({ items[i], prices[i], descriptions[i], 0, 0.0 });
    }
}


// Update the function definition to accept vectors
void updateSalesData(const vector<string>& itemNames, const vector<int>& quantities) {
    for (size_t i = 0; i < itemNames.size(); ++i) {
        for (auto& record : salesRecords) {
            if (record.itemName == itemNames[i]) {
                record.quantitySold += quantities[i];
                double itemTotal = record.price * quantities[i];
                record.totalSales += itemTotal;
                totalDailySales += itemTotal;
                break;
            }
        }
    }
}

void displayCurrentItems() {
    cout << "\nCurrent Items and Prices:\n";
    cout << "+----+----------------------+---------------------+\n";
    cout << "| No | Item                 | Price (RM)          |\n";
    cout << "+----+----------------------+---------------------+\n";
    for (size_t i = 0; i < salesRecords.size(); ++i) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(20) << left << salesRecords[i].itemName
            << " | " << setw(19) << right << fixed << setprecision(2) << salesRecords[i].price << " |\n";
    }
    cout << "+----+----------------------+---------------------+\n";
}

// Function to change item name and price
void changeItemAndPrice() {
    int itemIndex;
    string newName;
    double newPrice;

    displayCurrentItems();
    while (true) {
        cout << "\nEnter the number of the item you want to change (1-" << salesRecords.size() << "): ";
        cin >> itemIndex;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        else break;
    }

    if (itemIndex < 1 || itemIndex > salesRecords.size()) {
        cout << "Invalid item number.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new name for the item (or press Enter to keep current name): ";
    getline(cin, newName);

    if (!newName.empty()) {
        salesRecords[itemIndex - 1].itemName = newName;
    }

   
    while (true) {
        cout << "Enter new price for the item (or enter 0 to keep current price): ";
        cin >> newPrice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid price or 0 to keep current price." << endl;
            continue;
        }
        else {
            break;
        }
    }
    if (newPrice > 0) {
        salesRecords[itemIndex - 1].price = newPrice;
    }

    cout << "Item updated successfully.\n";
    displayCurrentItems();
}

void staffaccess() {
    char yeno;
    while (true) {
        cout << "Are you an admin? (Y/N)" << endl;
        cin >> yeno;
        yeno = toupper(yeno);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Y/N" << endl;
            continue;
        }
        else break;
    }
    if (yeno == 'N') {
        return;
    }
    else if (yeno == 'Y') {
        string password;
        while (true) {
            cout << "Enter password to access database" << endl;
            cin >> password;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a string" << endl;
            }
            else break;
        }
        if (password != "kali") {
            cout << "access denied" << endl;
            return;
        }
        else if (password == "kali") {
            system("cls");
            char isc;
            cout << "accessing to database..." << endl;
            cout << YELLOW << "ILLEGAL CAUTION " << RESET << BLUE << "DO NOT SHARE USER'S DATA TO ANYONE" << RESET << endl;
            cout << "According to Personal Data Protection Act (PDPA) 2010 Malaysia " << endl;
            cout << "Who compromised user data of an organization will faced a penalties" << endl;
            cout << "of fines up to RM 500,000 and/or imprisonment for up to 3years " << endl;

            // Display all user data
            for (const string& Userdata : userdata) {
                cout << Userdata << endl;
            }

            // New admin menu for changing items and prices
            char adminChoice;
            do {
                cout << "\nAdmin Menu:\n";
                cout << "1. Change item and price\n";
                cout << "2. Display current items\n";
                cout << "3. Profit Report\n";
                cout << "4. Exit admin mode\n";
                cout << "Enter your choice: ";
                cin >> adminChoice;

                switch (adminChoice) {
                case '1':
                    changeItemAndPrice();
                    break;
                case '2':
                    displayCurrentItems();
                    break;
                case '3':
                    generateProfitReport();
                    break;
                case '4':
                    cout << "Exiting admin mode...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (adminChoice != '4');

            while (true) {
                cout << "Please press(C) to clear screen" << endl;
                cin >> isc;
                isc = toupper(isc);
                if (isc == 'C') {
                    system("cls");
                    break;  // Exit the loop after clearing the screen
                }
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter a character (C)" << endl;
                }
            }
        }
    }
    else cout << "Enter Y/N" << endl;
}
// Main function
int main() {
    const int numItems = 6;
    string items[numItems] = { "MOBILE LEGEND", "FREE FIRE", "PUBG", "TALKING TOM", "ANGRY BIRD", "LEAGUE OF LEGEND" };
    double prices[numItems] = { 5.00, 10.00, 15.00, 20.00, 25.00, 30.00 };
    string descriptions[numItems] = {
        "Popular mobile MOBA game                          ",
        "Battle royale shooter game                        ",
        "Realistic battle royale game                      ",
        "Virtual pet simulator                             ",
        "Physics-based puzzle game                         ",
        "PC MOBA game                                      "
    };

    // Initialize sales records
    initializeSalesRecords(items, prices, descriptions, numItems);

    displayWelcome();

    while (true) {
        displayoption();
        int option;
        cout << "Please enter your choice : ";
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }


        switch (option) {
        case 1:
            placeOrder();
            break;
        case 2:
            generateSalesReport();
            break;
        case 3:
            cout << "Thank you for using the system. Goodbye!" << endl;
            return 0;
        case 4:
            staffaccess();

        default:
            cout << "Invalid option. Please select a valid choice." << endl;
            break;
        }
    }

    return 0;
}







