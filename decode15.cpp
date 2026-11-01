
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct customer {
         string Name;
         string Address;
         int Mobilenumber;
        };
        /***save ithis info with file handling using customer.txt */
        /**********make a  greet function which say hi or hello with customer name******/ 
void main_menu(){
    cout<<"Desi Foods:\n Biryani: 350Rs\n Nihari: 200Rs\n karahi: 800Rs per kg"<<endl;
    cout<<"Fast Food:\n Burger: 350Rs\n Pizza:500Rs\n Broast: 380Rs\n Tikka: 350Rs"<<endl;
    cout<<"Rolls:\n Chicken Roll: 120Rs\n Chatni Roll: 140Rs\n Mayo Roll: 170Rs"<<endl;
cout<<"Beverages:\n Cold Drink: 110Rs\n Apple juice: 160Rs\n Mango juice: 140Rs\n Water (Large bottle): 90Rs\n Water (Small Bottle) :50"<<endl;
}

void slip_calculation(int &totalamount,string &detailed,int quantity,string item,int prices){
        int amount= quantity* prices;
        totalamount = totalamount + amount;
// here we removed the line break from the past codes because it skips items in our .txt file
 detailed=detailed + " " + to_string(quantity) + item + to_string(amount);
}
int main()
{
    /*concepts that has been used so far:
    1)basic data types
    2)arrays
    3)loop(do-while)
    4)operators
    5)if/else
    6)switch
    7)strings along its function
    8)basic input/output
    9)Escape Sequence
     */
fstream record;    
customer info;    
int package;
string packing;    
string detailed="";    
int totalamount=0;
int bill=0;
int quantity;
int choice;
int dishes;
int prices[20]={350,200,800,120,250,380,350,120,140,170,110,160,140,90,50};

cout<<"Welcome to super quality foods"<<endl;
/*cout<<"Enter your Name"<<endl;
getline(cin,info.Name);
cout<<"Enter your Address"<<endl;
getline(cin,info.Address);
cout<<"Please! Enter your Mobile no"<<endl;
cin>>info.Mobilenumber;*/

cout<<"____________________________________________________________________\n WHAT SERVICES DO YOU REQUIRE SELECT THE CORRESPONDING NUMBER FOR IT\n___________________________________________________________________ "<<endl;

Start:
cout<<" 1.Show menu\n 2.Book your Oder\n 3.Order History\n 4.Exit"<<endl;
cin>>choice;
      if (choice==1)
{
    main_menu();
     goto Start;
    
}
  
else if (choice==2)
{
  cin.ignore();
 cout<<"Enter your Name"<<endl;
getline(cin,info.Name);
cout<<"Enter your Address"<<endl;
getline(cin,info.Address);
cout<<"Please! Enter your Mobile no"<<endl;
cin>>info.Mobilenumber;
   do{
   //  cout<<"Enter The Dish Number\n 1.Biryani: 350Rs \n 2.Nihari: 200Rs \n 3.karahi \n 4. Daal\n 5.Mix Sabzi\n 6.Burger \n7.Pizza\n 8.Broast\n 9.Tikka\n10.Chicken Roll \n11.Chicken Chatney Roll \n12.Mayo Roll \n13.Apple Juice \n14.Mango Juice \n15.Water (Large Bottle)\n16.Water (Small Bottle) \npress o for exit"<<endl;
    cout<<"Enter The Dish Number\n Desi Foods:\n 1.Biryani: 350Rs \n 2.Nihari: 200Rs \n 3.karahi \n 4. Daal\n 5.Mix Sabzi"<<endl;
  cout<<" Fast Foods:\n 6.Burger \n7.Pizza\n 8.Broast\n 9.Tikka\n 10.Chicken Roll \n 11.Chicken Chatney Roll \n 12.Mayo Roll"<<endl; 
  cout<<" BEVERAGES:\n 13.Cold Drink \n 14.Mango Juice\n 15.Apple Juice\n 16.Water (Large Bottle)\n 17.Water (Small Bottle)"<<endl;
  cin>>dishes;
     switch (dishes)
     {
     case 1:
        cout<<"Biryani: 350Rs"<<endl;
        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Biryani ",prices[0]);

        break;

         case 2:
         cout<< " Nihari: 200Rs " <<endl;
        cout<<" Select the quantity in kg "<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Nihari ",prices[1]);   
        break;

         case 3:
         cout<<" karahi: 800Rs"<<endl;

        cout<<"Select the quantity in kg"<<endl;
        cin>>quantity;   
        slip_calculation(totalamount,detailed,quantity," Karahi ",prices[2]); 
        break;
         case 4:
         cout<<" Daal: 120Rs"<<endl;
        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Daal ",prices[3]);
        break;

         case 5:
         cout<<" Mix Sabzi: 250Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Mix sabzi ",prices[4]);
        break;
           case 6:
         cout<<" Burger: 350Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Burger ",prices[5]);
        break;
           case 7:
         cout<<" Pizza:500Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Pizza ",prices[6]);
        break;
           case 8:
         cout<<" Broast: 380Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Broast ",prices[7]);
        break;
            case 9:
         cout<<"Tikka: 350Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Tikka ",prices[8]);
        break;
          case 10:
         cout<<"Chicken Roll: 120Rs"<<endl;
        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Chicken Roll ",prices[9]);
        break;
           case 11:
         cout<<"Chicken Chatni Roll: 140Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Chatni Roll ",prices[10]);
        break;
           case 12:
         cout<<"Mayo Roll: 170Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Mayo Roll ",prices[11]);
        break;
           case 13:
         cout<<"Cold Drink: 110Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Cold drink ",prices[12]);
        break;

           case 14:
         cout<<" Mango juice: 160Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Apple juice ",prices[13]);
        break;
           case 15:
         cout<<" Apple juice: 140Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Mango juice ",prices[14]);
        break;
           case 16:
         cout<<" Water (Large bottle): 90Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Water (Large bottle) ",prices[15]);
        break;
           case 17:
         cout<<" Water (small bottle): 50Rs"<<endl;

        cout<<"Select the quantity"<<endl;
        cin>>quantity;
        slip_calculation(totalamount,detailed,quantity," Water (small bottle) ",prices[16]);
        break;
       // detailed1=detailed1 + "\n" + detailed;debugging 3
     }
     //amount1=amount+amount1; Debugging 2
     //detailed1=detailed1 + "\n" + detailed;


    }while(dishes!=0);
      cout << "Enter packing: 1.Box packing\n 2.Plastic Bag\n 3.Tin Pack\n";
        cin >> package;
        packing = (package == 1) ? "Box" : (package == 2) ? "Bag" : "Tin";
    if (totalamount!=0)
{
    cout<<"************************YOUR BILL IS************************ "<<endl<<detailed<<"Packing: "<<packing<<endl<<"The total bill is "<<totalamount<<endl;
    record.open("text.txt", ios::app);
    record << "Phone:" << info.Mobilenumber << " | Name:" << info.Name << " | Items:" << detailed << " | Total:" << totalamount << "Rs" << endl;
    record.close();
}
    goto Start;
    
}
else if(choice ==3){
      string searchPhone;
        string line;
        bool found = false;
        
        cout << "Enter Mobile Number to search: ";
        cin >> searchPhone;

       record.open("text.txt", ios::in);
        cout << "\n--- SEARCHING RECORDS ---" << endl;
        
        // This loop reads every single LINE in the file
        while (getline(record, line)) {
            // If the searchPhone string is found anywhere in the current line
            if (line.find(searchPhone) != string::npos) {
                // It prints the ENTIRE line (which contains Name, Items, and Total)
                cout << line << endl;
                found = true;
            }
        }
        record.close();
          if (!found) cout << "No history found for this number." << endl;
        goto Start;
      }
//cout<<detailed1; debugging 1

else
{
    cout<<"************************YOUR BILL IS************************"<<bill<<endl;
    cout<<"Thank you for visting  us"<<endl;
} 
return 0;
}