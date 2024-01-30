#include <iostream>

using namespace std;

int main()
{

    int choice;

    while(true)
    {

        cout << "\n-------------------------------------------------------\n";
        cout << "            Multi-Digit Calculator Project             \n";
        cout << "-------------------------------------------------------\n";
        cout << "Operations Menu: \n";
        cout << "Enter 1 for addition.\n"
                "Enter 2 for subtraction.\n"
                "Enter 3 for multiplication.\n"
                "Enter 4 for division.\n"
                "Enter 5 for modulus.\n"
                "Enter 0 to exit.\n"
                "Your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int number1[15] = {0};
                int number2[15] = {0};
                int sum[16] = {0};
                int carry = 0;

                cout << "\n-------------------------------------------------------\n";
                cout << "                  Addition                               \n";
                cout << "-------------------------------------------------------\n\n";

                cout << "Enter First Number(15-digits as seperate digits): ";
                for(int i = 0; i < 15; i++)
                    cin >> number1[i];

                cout << "Enter Second Number(15-digits as seperate digits): ";
                for(int i = 0; i < 15; i++)
                    cin >> number2[i];

                cout << "First Number: ";
                for(int i = 0; i < 15; i++)
                    cout << number1[i];
                cout << endl;

                cout << "Second Number: ";
                for(int i = 0; i < 15; i++)
                    cout << number2[i];
                cout << endl;
                
                for(int i = 14, j = 15; i >= 0; i--)
                {
                    int temp = number1[i] + number2[i] + carry;
                    carry = 0;

                    if(temp > 9)
                    {
                        sum[j] = temp % 10;
                        carry = temp / 10;
                        j--;
                    }
                    else
                    {
                        sum[j] = temp;
                        j--;
                    }
                }
                sum[0] = carry;

                cout << "Sum of Numbers: ";
                for(int i = 0; i < 16; i++)
                    cout << sum[i];
                cout << endl;

                cout << "\n-------------------------------------------------------\n";

                break;
            }

            case 2:
            {

                int number1[15] = {0};
                int number2[15] = {0};
                int subtract[15] = {0};

                cout << "\n-------------------------------------------------------\n";
                cout << "                  Subtraction                            \n";
                cout << "-------------------------------------------------------\n\n";

                cout << "Note: Number 1 should be greater than number 2 for subtraction.\n";
                cout << "\n---------------------------------------------------------------\n\n";

                cout << "Enter First Number(15-digits as seperate digits): ";
                for(int i = 0; i < 15; i++)
                    cin >> number1[i];

                cout << "Enter Second Number(15-digits as seperate digits): ";
                for(int i = 0; i < 15; i++)
                    cin >> number2[i];

                cout << "First Number: ";
                for(int i = 0; i < 15; i++)
                    cout << number1[i];
                cout << endl;

                cout << "Second Number: ";
                for(int i = 0; i < 15; i++)
                    cout << number2[i];
                cout << endl;

                for(int i = 14; i >= 1; i--)
                {
                    if(number1[i] >= number2[i])
                    {
                        subtract[i] = number1[i] - number2[i];
                    }
                    else
                    {
                        int count = 0;
                        for(int j = i - 1; j >= 0; j--)
                        {
                            count++;
                            if(number1[j] > 0) 
                            {
                                number1[j] = number1[j] - 1;
                                for(int k = 0; k < count - 1; k++)
                                {
                                    j++;
                                    number1[j] = number1[j] + 10;
                                    number1[j] = number1[j] - 1;
                                }
                                break;
                            }
                        }
                        number1[i] = number1[i] + 10;
                        subtract[i] = number1[i] - number2[i];
                    }
                }
                subtract[0] = number1[0] - number2[0];

                cout << "Subtraction of Numbers: ";
                for(int i = 0; i < 15; i++)
                    cout << subtract[i];
                cout << endl;

                cout << "\n-------------------------------------------------------\n";

                break;
            }

            case 3:
            {
                int number1[15] = {0};
                int number2[3] = {0};
                int layer[16] = {0};
                int product[18] = {0};
                int carry = 0;

                cout << "\n-------------------------------------------------------\n";
                cout << "                  Multiplication                         \n";
                cout << "-------------------------------------------------------\n\n";

                cout << "Note: For Multiplication, Division and Modulus the Range of \n"
                        "Second Number is between 0-999.\n"
                        "If you want to enter a 1 or 2 digit number for Second Number,\n"
                        "enter it by adding 0's to start to complete a 3 digit number.\n";
                cout << "\n--------------------------------------------------------------------\n\n";

                cout << "Enter First Number(15-digits as seperate digits): ";
                for(int i = 0; i < 15; i++)
                    cin >> number1[i];

                cout << "Enter Second Number(3-digits as seperate digits | max 999): ";
                for(int i = 0; i < 3; i++)
                    cin >> number2[i];

                cout << "First Number: ";
                for(int i = 0; i < 15; i++)
                    cout << number1[i];
                cout << endl;

                cout << "Second Number: ";
                for(int i = 0; i < 3; i++)
                    cout << number2[i];
                cout << endl;

                int j = 2;
                for(int count = 0; count < 3; count++)
                {
                    for(int i = 14; i >= 0; i--)
                    {
                        int temp = number1[i] * number2[j] + carry;
                        carry = 0;
                        if(temp > 9)
                        {
                            layer[i + 1] = temp % 10;
                            carry = temp / 10;
                        }
                        else
                            layer[i + 1] = temp;
                    }
                    layer[0] = carry;
                    carry = 0;
                    
                    for(int i = 16; i >= 0; i--)
                    {
                        int temp = product[i + j] + layer[i] + carry;
                        carry = 0;
                        if(temp > 9){
                            product[i + j] = temp % 10;
                            carry = temp / 10;
                        }
                        else
                            product[i + j] = temp;
                    }

                    j--;
                }

                cout << "Product of Numbers: ";
                for(int i = 0; i < 18; i++)
                    cout << product[i];
                cout << endl;

                cout << "\n-------------------------------------------------------\n";

                break;
            }

            case 4:
            {

                int number1[15] = {0};
                int number2 = 0;
                int division[15] = {0};

                cout << "\n-------------------------------------------------------\n";
                cout << "                        Division                         \n";
                cout << "-------------------------------------------------------\n\n";

                cout << "Note: For Multiplication, Division and Modulus the Range of \n"
                        "Second Number is between 0-999.\n"
                        "If you want to enter a 1 or 2 digit number for Second Number,\n"
                        "enter it by adding 0's to start to complete a 3 digit number.\n";
                cout << "\n--------------------------------------------------------------------\n\n";

                cout << "Enter First Number(15-digits as seperate digits): ";
                for(int i = 0; i < 15; i++)
                    cin >> number1[i];

                cout << "Enter Second Number(3-digits as combined digits | max 999): ";
                cin >> number2;

                cout << "First Number: ";
                for(int i = 0; i < 15; i++)
                    cout << number1[i];
                cout << endl;

                cout << "Second Number: ";
                cout << number2 << endl;

                int index = 0;
                int temp = number1[index];
                while (temp < number2)
                {
                    temp = temp * 10;
                    index++;
                    temp = temp + number1[index];
                }
                int i = 0;
                while (index < 15) 
                {
                    division[i] = temp / number2;
                    index++;
                    temp = (temp % number2) * 10;
                    temp = temp + number1[index];
                    i++;
                }

                cout << "Division Result: ";
                for(int j = 0; j < i; j++)
                    cout << division[j];

                cout << "\n-------------------------------------------------------\n";

                break;
            }

            case 5:
            {

                int number1[15] = {0};
                int number2 = 0;

                cout << "\n-------------------------------------------------------\n";
                cout << "                         Modulus                         \n";
                cout << "-------------------------------------------------------\n\n";

                cout << "Note: For Multiplication, Division and Modulus the Range of \n"
                        "Second Number is between 0-999.\n"
                        "If you want to enter a 1 or 2 digit number for Second Number,\n"
                        "enter it by adding 0's to start to complete a 3 digit number.\n";
                cout << "\n--------------------------------------------------------------------\n\n";

                cout << "Enter First Number(15-digits as seperate digits): ";
                for(int i = 0; i < 15; i++)
                    cin >> number1[i];

                cout << "Enter Second Number(3-digits as seperate digits | max 999): ";
                cin >> number2;

                cout << "First Number: ";
                for(int i = 0; i < 15; i++)
                    cout << number1[i];
                cout << endl;

                cout << "Second Number: ";
                cout << number2 << endl;

                int remainder = 0;
                for (int i = 0; i < 15; i++) 
                {
                    remainder = remainder * 10;
                    remainder = remainer + number1[i];
                    remainder = remainder % number2;
                }   

                cout << "Modulus of Numbers: " << remainder << endl;

                cout << "\n-------------------------------------------------------\n";

                break;
            }

            case 0:
            {   
                cout << "\n-------------------------------------------------------\n";
                cout << "                Program Terminated.                    \n";
                cout << "-------------------------------------------------------\n\n";
                return 0;
            }
        }
    }
}
