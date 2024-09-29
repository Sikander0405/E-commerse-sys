#include <iostream>
#include <string>
using namespace std;

auto space(const string str, int width)
{

    int spaceLength = width - str.length();
    return str + string(spaceLength > 0 ? spaceLength : 0, ' ');
}

void choice()
{
    cout << "Type 's' if you are a seller or type 'c' if you are a customer." << endl;
    cout << "Or type any other letter to stop." << endl;
}

int seller(int count, string product[][4])
{
    char s;
    string id, p, n, d;
    int idWidth = 12;
    int nameWidth = 20;
    int priceWidth = 15;
    int descWidth = 30;

    cout << "Type 'a' to add product." << endl;
    cout << "Type 'd' to delete product." << endl;
    cout << "Type 's' to see your added products." << endl;
    cout << "Type 'c' to change price." << endl;
    cout << "Type 'n' to change name." << endl;
    cout << "type 'm' to change description." << endl;
    cout << "Type 'b' to go back." << endl;
    cin >> s;

    if (s == 'a')
    {
        if (count >= 100)
        {
            cout << "Product limit reached. Cannot add more products." << endl;
            return count;
        }

        cout << "Create a product id: ";
        cin >> id;

        for (int i = 0; i < count; ++i)
        {
            if (product[i][0] == id)
            {
                cout << "ID already exists, try again." << endl
                     << endl;
                return seller(count, product);
            }
        }

        product[count][0] = id;

        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, n);
        product[count][1] = n;

        cout << "Add samll description about the product : ";

        getline(cin, d);
        product[count][3] += d;

        cout << "Enter price: ";
        cin >> p;
        product[count][2] = p;

        cout << "Your product is added." << endl
             << endl;
        ++count;
        return seller(count, product);
    }
    else if (s == 'c')
    {
        cout << "Enter product id: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (product[i][0] == id)
            {
                cout << "Old price: " << product[i][2] << endl;
                cout << "Enter new price: ";
                cin >> p;
                product[i][2] = p;
                cout << "Your price is updated." << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Product ID not found." << endl;
        }

        return seller(count, product);
    }
    else if (s == 'd')
    {
        cout << "Enter product id: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (product[i][0] == id)
            {
                product[i][0] = "0";
                cout << "Your product is no longer for sale." << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Product ID not found." << endl
                 << endl;
        }

        return seller(count, product);
    }
    else if (s == 'n')
    {
        cout << "Enter product id: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (product[i][0] == id)
            {
                cout << "Old name: " << product[i][1] << endl;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, n);
                product[i][1] = n;
                cout << "Product name updated." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Product ID not found." << endl;
        }

        return seller(count, product);
    }

    else if (s == 's')
    {
        bool found = false;
        for (int i = 0; i <= count; ++i)
        {
            if (product[i][0] != "0")
            {
                if (i < 1)
                {
                    cout << space("Product ID", idWidth)
                         << space("Product Name", nameWidth)
                         << space("Price", priceWidth)
                         << space("Description", descWidth) << endl;
                }

                cout << space(product[i][0], idWidth)
                     << space(product[i][1], nameWidth)
                     << space(product[i][2], priceWidth)
                     << space(product[i][3], descWidth) << endl;
                found = true;
            }

        }
        cout<<endl;
            if (found)
            {
                return seller(count, product);
            }

            else if (product[count - 1][0] == "0")
            {

                cout << "No products added." << endl;
                return seller(count, product);
            }
    }

    else if (s == 'm')
    {
        cout << "enter product ID:";
        cin >> id;

        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (product[i][0] == id)
            {
                cout << "Old description :" << product[i][3] << endl;
                cout << "enter new description :";
                cin.ignore();
                getline(cin, d);
                product[i][3] = d;
                cout << "Product description added." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Product ID not found." << endl;
        }
        return seller(count, product);
    }
    else if (s == 'b')
    {
        cout << "Thank you..." << endl;
        return count;
    }
    else
    {
        cout << "Invalid input." << endl;
        return seller(count, product);
    }
}

void customer(int count, string product[][4], string kart[][4])
{
    char q;
    string j;
    int idWidth = 12;
    int nameWidth = 20;
    int priceWidth = 15;
    int descWidth = 30;

    cout << "Type 'e' to explore products" << endl;
    cout << "Type 'k' to see your kart." << endl;
    cout << "Type 'r' to remove product from your kart." << endl;
    cout << "Type 'b' to go back." << endl;
    cin >> q;

    if (q == 'e')
    {
        for (int i = 0; i <= count; ++i)
        {
            if (product[i][0] != "0")
            {
                if (i < 1)
                {
                    cout << space("Product ID", idWidth)
                         << space("Product Name", nameWidth)
                         << space("Price", priceWidth)
                         << space("Description", descWidth) << endl;
                }

                cout << space(product[i][0], idWidth)
                     << space(product[i][1], nameWidth)
                     << space(product[i][2], priceWidth)
                     << space(product[i][3], descWidth) << endl;
            }

            else if (product[count - 1][0] == "0")
            {

                cout << "No products added." << endl;
                return customer(count, product, kart);
            }
        }

        cout << "Enter product id which you want to add to kart or 'b' to go back: ";
        cin >> j;

        if (j == "b")
        {
            return customer(count, product, kart);
        }

        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (product[i][0] == j)
            {
                kart[i][0] = j;
                cout << "Your product is added to your kart." << endl;
                cout << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Product not in the list." << endl;
        }

        customer(count, product, kart);
    }
    else if (q == 'k')
    {
        bool empty = true;
        int head=0;
        for (int i = 0; i < count; ++i)
        {
            if (kart[i][0] != "0")
            {
                if (head==0)
                {
                    cout << space("Product ID", idWidth)
                         << space("Product Name", nameWidth)
                         << space("Price", priceWidth)
                         << space("Description", descWidth) << endl;
                }

                cout << space(kart[i][0], idWidth)
                     << space(product[i][1], nameWidth)
                     << space(product[i][2], priceWidth)
                     << space(product[i][3], descWidth) << endl;
                empty = false;
                head++;
            }

        }
            if (empty)
            {
                cout << "Your kart is empty." << endl
                     << endl;
            }

        customer(count, product, kart);
    }
    else if (q == 'r')
    {
        cout << "Enter product id: ";
        cin >> j;

        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (kart[i][0] == j)
            {
                kart[i][0] = "0";
                cout << "Product removed from kart." << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Product not in your kart." << endl
                 << endl;
        }

        customer(count, product, kart);
    }
    else if (q == 'b')
    {
        cout << "Thank you..." << endl;
    }
    else
    {
        cout << "Invalid input." << endl;
        customer(count, product, kart);
    }
}

void callfun(char c, int &count, string product[][4], string kart[][4]);

int main()
{
    cout << "Welcome to Apka Dukan!!" << endl;
    int count = 0;
    char c;

    choice();
    cin >> c;
    if (c != 's' && c != 'c')
    {
        cout << "Thank you..." << endl;
        return 0;
    }

    string product[100][4];
    string kart[100][4];

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            product[i][j] = "0";
            product[i][3] = " ";
            kart[i][j] = "0";
        }
    }

    callfun(c, count, product, kart);

    return 0;
}

void callfun(char c, int &count, string product[][4], string kart[][4])
{
    if (c == 's')
    {
        count = seller(count, product);
        choice();
        cin >> c;
        if (c != 's' && c != 'c')
        {
            cout << "Thank you..." << endl;
            return;
        }
        callfun(c, count, product, kart);
    }
    else if (c == 'c')
    {
        customer(count, product, kart);
        choice();
        cin >> c;
        if (c != 's' && c != 'c')
        {
            cout << "Thank you..." << endl;
            return;
        }
        callfun(c, count, product, kart);
    }
}
