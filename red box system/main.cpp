

#include<iostream>
#include<vector>
#include<string>
#include<ctime>

#include"loans.h"

using namespace std;


//Ent_items *Ent_item=new Ent_item;// a var of type item, to add item
game *editgame=new game;
Movie*editmovie=new Movie;
Ent_items Entitemz;
int itemsearch=0;
unsigned int j=0;
char editOption;
double repcost;

int main(){
    /***********************************************/
    int choice=100;
    double Item_Cost=0.0;//Item coast
    char ItemStatuS;// Item status
    int loanperioD;//loan period for item
    int Item_ID=0;// item id
    char item_type;
    int check=0;
    /**********************************************/
    string mtitle;
    string Authname;
    string mrating;

    int yearpublish=0;// movie publish year
    int isBn;
    /*******************************************/
    string cdname;
    string artisT_name;
    int tracks_number;
    string date_rel;
    string cd_gen;
    /******************************************/
    string dvd_names;
    string dvd_catg;
    double dvd_length;
    string dvd_STudio;
    /******************************************/
        time_t currentT=time(0);
        struct tm localnow;
        localnow=*localtime(&currentT); 
        int current_sec;
    /******************************************/
    Patron librarypatrons;
    Patrons mypatrons;
    Patron edit_patrons; 
    string patName;
    int PatvecSize=0;
    int Pat_IDn=0;
    int Pat_booksN=0;
    double fineonPat=0.0;
    int day_Borrow;
    int search_patid=0;
    string day_Return;
    /******************************************/
    Loan Myloan;// an object of type loan
    Loans Myloans;// a object of type loans
    int loaN_id=0;//loan id
    int newLid=0;//a variable for the new loan id
    int PAt_id=0;//patron id for loan
    vector<int> BookS_ID;// book id for loan
    int Nmbr_bks=0;//number of books for a loan
    int Lduration=0;//how many days would the loans be for?
    char L_Stat;// current statues of loan
    int Lostitem=0;
    string Person_name;
    /******************************************/
    while(choice!=0)
    {
        cout<<"Item MENU"<<endl;
        cout<<"(1) Add a new Item to the library: \n";
        cout<<"(2) Edit Item"<<endl;
        cout<<"(3) delete an Item"<<endl;
        cout<<"(4) search for a Item"<<endl;
        cout<<"(5) update item status"<<endl;
        cout<<"(6) print based on item ID"<<endl;
        cout<<"(7) Print all Items"<<endl;
        cout<<"(55) Load patrons\n";
        cout<<"********************************\n";
        cout<<"Patron MENU"<<endl;
        cout<<"(8) Add a patron"<<endl;
        cout<<"(9) Edit a Patron"<<endl;
        cout<<"(10) delete a Patron"<<endl;
        cout<<"(11) update the fines for a specific patron"<<endl;
        cout<<"(12) update the number of books for a specific patron"<<endl;
        cout<<"(13) Print overdues for a patron"<<endl;
        cout<<"(14) Print all info about Patrons"<<endl;
        cout<<"(15) Print all info for a specific Patron"<<endl;
        cout<<"********************************\n";
        cout<<"LOANS MENU\n";
        cout<<"(16) Check out an item\n";
        cout<<"(17) Check in item\n";
        cout<<"(18)List all items for a specific patron based on patron id\n";
        cout<<"(19)Edit a loan\n";
        cout<<"(20) Report Lost\n";

        /**************************************************************************/
        cout<<"Enter your choice\n";
        cin>>choice;
             if(choice==1)
            {
               
                cout<<"Enter the Item info\n";
                cout<<"enter the item type\n";
                cout<<"\nEnter b for book\nEnter c for audiocd\nEnter d for dvd\n: ";
                cin>>item_type;

                if(item_type=='m')
                {
                    
                    cout<<"enter the Item ID number: " <<endl;
                    cin>>Item_ID;
                    cout<<"\nenter the title of book: " <<endl;
                    cin.ignore();
                    getline(cin, mtitle);
                    //cin.ignore();
                    //cin.ignore();
                    cout<<"\nenter the rating of the movie: " <<endl;
                    cin.ignore();
                    getline(cin, mrating);
                    cout<<"\nenter the movie cost as a double: " <<endl;
                    cin>>Item_Cost;
                    cout<<"\nenter the movie replacment cost as a double: " <<endl;
                    cin>>repcost;
                    cout<<"\nenter the realese date of the movie: " <<endl;
                    cin>>yearpublish;
                    cout<<"\nenter the current status of the item as 'a' for Avaliable or as 'o' for out or 'l'for lost   : " <<endl;
                    cin>>ItemStatuS;
                    cout<<"\nEnter the loan period avaliable for this item:\n";
                    cin>>loanperioD;
                    //now send the data to the vector
                    editmovie->setTitle(movietitle)
                    editmovie->set
                    editmovie->setGenre(mrating);
                    editmovie->setItemId(Item_ID);
                    editmovie->setItemCost(Item_Cost);
                    editmovie->setPublishYear(yearpublish);
                    editmovie->setItemStatus(ItemStatuS);
                    editmovie->setLibraryID(Libid);
                    editmovie->setLoanperiod(loanperioD);
                    Entitemz.addItem(editmovie);
                }
                if(item_type=='c')
                {
                    
                    cout<<"\n enter info for a new cd\n";
                    cout<<"enter the Item ID number : " <<endl;
                    cin>>Item_ID;
                    cout<<"\nenter the name of Audio CD: " <<endl;
                    cin.ignore();
                    getline(cin, cdname);
                    //cin.ignore();
                    cout<<"\nenter the name of the CD artisit: "<<endl;
                    cin.ignore();
                    getline(cin,artisT_name);
                    //cin.ignore();
                    cout<<"\nenter the Genre of CD: " <<endl;
                    cin.ignore();
                    getline(cin, cd_gen);
                    cout<<"enter the number of tracks in the CD : " <<endl;
                    cin>>tracks_number;
                    cout<<"\nenter the CD cost of book as a double: " <<endl;
                    cin>>Item_Cost;
                    cout<<"\nenter the cd release year: " <<endl;
                    cin>>date_rel;
                    cout<<"\nenter the current status of the book as 'a' for avliable or as 'o' for out, and 'l'for lost   : " <<endl;
                    cin>>ItemStatuS;
                    cout<<"\nEnter the loan period avaliable for this item:\n";
                    cin>>loanperioD;
                    //libritem=new Audiocd(id, stat,);
                    cd->setArtist_name(artisT_name);
                    cd->setCD_name(cdname);
                    cd->setGenre_CD(cd_gen);
                    cd->setItemCost(Item_Cost);
                    cd->setItemId(Item_ID);
                    cd->setItemStatus(ItemStatuS);
                    cd->setLoanperiod(loanperioD);
                    cd->setNumbertracks(tracks_number);
                    cd->SetreleaseDate(date_rel);
                    libraryItems.addItem(cd);
                   // delete libritem;
                    
                }
                 if(item_type=='d')
                {
                    cout<<"\n enter info for a new DVD\n";

                    cout<<"enter the Item ID number : " <<endl;
                    cin>>Item_ID;
                    cout<<"\nenter the name of DVD: " <<endl;
                    cin.ignore();
                    getline(cin, dvd_names);
                    //cin.ignore();
                    cout<<"\nenter the Category of DVD: " <<endl;
                    cin.ignore();
                    getline(cin, dvd_catg);
                    cout<<"\nenter the Run time for the DVD as a double : " <<endl;
                    cin>>dvd_length;
                    cout<<"\n enter the name of the studio that made the DVD:\n";
                    getline(cin, dvd_STudio);
                    cout<<"\nenter the DVD cost as a double: " <<endl;
                    cin>>Item_Cost;
                    cout<<"\nenter the DVD release year: " <<endl;
                    cin>>date_rel;
                    cout<<"\nenter the current status of the book as 'a' for avaliable or  'o' for out, and 'l'for lost : " <<endl;
                    cin>>ItemStatuS;
                    cout<<"\nEnter the loan period avaliable for this item:\n";
                    cin>>loanperioD;
                    dvd->setdvdCategory(dvd_catg);
                    dvd->setdvdName(dvd_names);
                    dvd->setdvdRealese(date_rel);
                    dvd->setdvdtime(dvd_length);
                    dvd->setItemCost(Item_Cost);
                    dvd->setItemId(Item_ID);
                    dvd->setItemStatus(ItemStatuS);
                    dvd->setLoanperiod(loanperioD);
                    dvd->setStudio(dvd_STudio);
                    libraryItems.addItem(dvd);
                }
                    


            }
            
            
        
        if(choice==2)
        {

            cout<<"\nTo eidt an Item enter what type of item do you want to edit?\n"<<endl<<endl;
            cout<<"enter 'b' to edit a book\n enter 'c' to edit audiocd\n enter 'd' to edit a DVD\n";
            cin>>item_type;
            cout<<"Eter the id for the book you want to edit "<<endl;
            cin>>Item_ID;
            check=libraryItems.searchInfo(Item_ID);

            if(check!=-1)
            {
                if(item_type=='b')
                {
                    cout<<"enter the NEW item Id number:"<<endl;
                    cin>>new_BookId;
                    cout<<"\nEnter the new name for the book you want to edit"<<endl;
                    cin.ignore();
                    getline(cin,Nbook);
                    cout<<"\nEnter the new author for the book:"<<endl;
                    cin.ignore();
                    getline(cin,Authname);
                    cout<<"\nEnter the new book genre:"<<endl;
                    getline(cin,mrating);
                    cout<<"Enter the NEW library id:"<<endl;
                    cin>>Libid;
                    cout<<"\nEnter the new price of the book:"<<endl;
                    cin>>Item_Cost;
                    cout<<"\nEnter the new Publishing year: "<<endl;
                    cin>>yearpublish;
                    cout<<"\nEnter the new book status 'n' for normal or as 'o' for overdue: "<<endl;
                    cin>>ItemStatuS;
                    cout<<"\nEnter the new loan period avaliable for this item:\n";
                    cin>>loanperioD;

                    editmovie->setAuthorName(Authname);
                    editmovie->setBookName(Nbook);
                    editmovie->setItemId(Item_ID);
                    editmovie->setLibraryID(Libid);
                    editmovie->setItemCost(Item_Cost);
                    editmovie->setGenre(mrating);
                    editmovie->setPublishYear(yearpublish);
                    editmovie->setItemStatus(ItemStatuS);
                    editmovie->setLoanperiod(loanperioD);

                    libraryItems.editItem(editmovie, new_BookId, item_type);
                }
                if(item_type=='c')
                {
                    cout<<"enter the NEW item Id number:"<<endl;
                    cin>>new_BookId;
                    cout<<"\nEnter the new name for the CD you want to edit"<<endl;
                    cin.ignore();
                    getline(cin,cdname);
                    cout<<"\nEnter the new Artist for the CD:"<<endl;
                    cin.ignore();
                    getline(cin,artisT_name);
                    cout<<"\nEnter the new CD genre:"<<endl;
                    getline(cin,cd_gen);
                    cout<<"Enter the NEW number of tracks in the CD:"<<endl;
                    cin>>tracks_number;
                    cout<<"\nEnter the new price of the CD:"<<endl;
                    cin>>Item_Cost;
                    cout<<"\nEnter the new release year: "<<endl;
                    cin>>date_rel;
                    cout<<"\nEnter the new book status 'n' for normal or as 'o' for overdue: "<<endl;
                    cin>>ItemStatuS;
                    cout<<"\nEnter the new loan period avaliable for this item:\n";
                    cin>>loanperioD;
                    
                    cd->setArtist_name(artisT_name);
                    cd->setCD_name(cdname);
                    cd->setGenre_CD(cd_gen);
                    cd->setItemCost(Item_Cost);
                    cd->setItemId(Item_ID);
                    cd->setItemStatus(ItemStatuS);
                    cd->setLoanperiod(loanperioD);
                    cd->setNumbertracks(tracks_number);
                    cd->SetreleaseDate(date_rel);
                    libraryItems.editItem(cd, new_BookId, item_type);

                }
                if(item_type=='d')
                {
                    cout<<"\n enter info for a new DVD\n";

                    cout<<"enter the new Item ID number : " <<endl;
                    cin>>new_BookId;
                    cout<<"\nenter the new name of DVD: " <<endl;
                    cin.ignore();
                    getline(cin, dvd_names);
                    //cin.ignore();
                    cout<<"\nenter the new Category of DVD: " <<endl;
                    cin.ignore();
                    getline(cin, dvd_catg);
                    cout<<"\nenter the new Run time for the DVD as a double : " <<endl;
                    cin>>dvd_length;
                    cout<<"\n enter the new name of the studio that made the DVD:\n";
                    getline(cin, dvd_STudio);
                    cout<<"\nenter the new DVD cost as a double: " <<endl;
                    cin>>Item_Cost;
                    cout<<"\nenter the new DVD release year: " <<endl;
                    cin>>date_rel;
                    cout<<"\nenter the new status of the book as 'a' for avaliable or  'o' for out, and 'l'for lost : " <<endl;
                    cin>>ItemStatuS;
                    cout<<"\nEnter the new loan period avaliable for this item:\n";
                    cin>>loanperioD;
                    dvd->setdvdCategory(dvd_catg);
                    dvd->setdvdName(dvd_names);
                    dvd->setdvdRealese(date_rel);
                    dvd->setdvdtime(dvd_length);
                    dvd->setItemCost(Item_Cost);
                    dvd->setItemId(Item_ID);
                    dvd->setItemStatus(ItemStatuS);
                    dvd->setLoanperiod(loanperioD);
                    dvd->setStudio(dvd_STudio);
                    libraryItems.editItem(dvd, new_BookId, item_type);


                }

                
            }
            else
            {
                cout<<"\nItem not found, search again. \n";
                
            }
            
        }

        if(choice==3)
        {
            Item_ID=0;
            cout<<"Delete an Item\n";
            cout<<"\nEnter the Item Id for the Item that you want to delete:"<<endl;
            cin>>Item_ID;
            libraryItems.deleteItem(Item_ID);
        }

        if(choice==4)
        {
            Item_ID=0;
            cout<<"\nSearch for an Item based on the item Id number\n";
            cout<<"\nEnter the id number for the Item you want to find:\n";
            cin>>Item_ID;
            libraryItems.searchInfo(Item_ID);
        }
        if(choice==5)
        {
            Item_ID=0;
            cout<<"Update Item status "<<endl;
            cout<<"\nenter the id number for the Item you want to update the status of: \n";
            cin>>Item_ID;
            cout<<"\nenter the new status for the book as 'n' for in,'o' for out, or 'l' for lost \n";
            cin>>ItemStatuS;
            libraryItems.updateStatus(Item_ID,ItemStatuS);
        }
        if(choice==6)
        {
            cout<<"Print item based on ID: \n";
            cout<<"\nEnter the item ID you want to print the data for:";

            cin>>itemsearch;
            libraryItems.printSpecificInfo(itemsearch);
        }
        if (choice==7)
        {
            cout<<"\nPrint all the Items in the library:\n";
            libraryItems.printAllInfo();
        }
        if(choice==8)
        {
            Pat_IDn=0;
            cout<<"\nAdd a patron\n";

                cout<<"\nEnter the name of patron " <<endl;
                cin.ignore();
                getline(cin, patName);
                cout<<"\nEnter the Patron Id number for Patron: "<<endl;
                cin>>Pat_IDn;
                cout<<"\nenter the Patron Fines for Patron: "<<endl;
                cin>>fineonPat;
                cout<<"\enter the number of books that the Patron: "<< " Borrowed: "<<endl;
                cin>>Pat_booksN;
                cout<<"\nenter how many days the patron Borrowed the books for patron:"<<endl;
                cin>> day_Borrow;
                cout<<"Enter which day should the patron  Return the books\n";
                getline(cin,day_Return);
                //sending the values to the vector
                librarypatrons.SetName(patName);
                librarypatrons.SetId(Pat_IDn);
                librarypatrons.SetBooksborrowed(Pat_booksN);
                librarypatrons.SetFine(fineonPat);
                librarypatrons.SetDaysborrowed(day_Borrow);
                //librarypatrons.SetReturnday(day_Return);

                mypatrons.addPatron(librarypatrons);
        }
        
        if(choice==9)
        {
            Pat_IDn=0;
            cout<<"Edit a patron\n";
            cout<<"enter the id number for the patron you want to edit:\n";
            cin>>search_patid;
            check=mypatrons.searchPatron(search_patid);
            if(check!=-1){
                cout<<"enter the new patron id number:\n";
                cin>>Pat_IDn;
                cout<<"enter the new patron name:\n";
                cin.ignore();
                getline(cin, patName);
                cout<<"enter the new number of book for the patron:\n";
                cin>>Pat_booksN;
                cout<<"enter the new fine/overduew on the patron: \n";
                cin>>fineonPat;
                cout<<"enter how many days is the patron going to borrow the books: \n";
                cin>>day_Borrow;
                cout<<"enter the new return date as a sentence: \n";
                cin.ignore();
                getline(cin, day_Return);
                //setting data
                edit_patrons.SetName(patName);
                edit_patrons.SetId(search_patid);
                edit_patrons.SetFine(fineonPat);
                edit_patrons.SetDaysborrowed(day_Borrow);
                edit_patrons.SetBooksborrowed(Pat_booksN);
                mypatrons.editPatron(edit_patrons,Pat_IDn,check);

            }
            else
            {
                cout<<"\nPatron was not found, nothing edited\n";
            }
            

        }

        if(choice==10){
            Pat_IDn=0;
            cout<<"Delete a patron:\n";
            cout<<"enter the Patron ID for the patron you want to delte:\n";
            cin>>Pat_IDn;
            mypatrons.deletePatron(Pat_IDn);
        }

        if(choice==11){
            Pat_IDn=0;
            cout<<"update the fines for a specific patron\n"<<endl;
            cout<<"enter the patron id you want to update the fines for:\n";
            cin>>Pat_IDn;
            cout<<"enter the new fine on the patron: \n";
            cin>>fineonPat;
            mypatrons.updateFines(Pat_IDn, fineonPat);
        }
        if(choice==12){
            Pat_IDn=0;
            Pat_booksN=0;
            cout<<"update the number of books for a specific patron"<<endl;
            cout<<"Enter the Patron id for the Patron you want to update books for:\n";
            cin>>Pat_IDn;
            cout<<"Enter the new amount of Books: \n";
            cin>>Pat_booksN;
            mypatrons.updatebooks_patron(Pat_IDn,Pat_IDn);

        }
        if(choice==13){
            Pat_IDn=0;
            cout<<"Print overdues for a patron"<<endl;
            cout<<"Enter the ID Number for the patron you want to change: \n";
            cin>>Pat_IDn;
            mypatrons.printOverdues(Pat_IDn);
        }
        if(choice==14){
            cout<<" Print all info about Patrons"<<endl;
            mypatrons.printAllInfo();
        }
        if (choice==15)
        {
            Pat_IDn=0;
            cout<<"Print all info for a specific Patron"<<endl;
            cout<<"Enter the ID Number for the patron you want to print info of: \n";
            cin>>Pat_IDn;
            mypatrons.print_allinfo_Patron(Pat_IDn);
        }
        if(choice==16)
        {
            cout<<"\nCheck out a loan\n";
            cout<<"\nTo create a new loan:\n";
            cout<<"\nenter the person Name :\n";
            cin.ignore();
            getline(cin, Person_name);
            cout<<"\nEnter the Loan id:\n";
            cin>>loaN_id;
            cout<<"\nEnter the Patron Id number:\n";
            cin>>PAt_id;
            cout<<"Enter the Number of books on this Loan:\n";
            cin>>Nmbr_bks;
            BookS_ID.resize(Nmbr_bks);
            cout<<"Enter the id for the books in the loan:\n";
            for(j=0;j<BookS_ID.size();j++)
            {
            cout<<"\nEnter the id for book: "<<j+1<<" :\n";
            cin>>BookS_ID.at(j);
            }
            cout<<"\nEnter the current status of the loan as 'o' for overdue or as'n' for normal :\n";
            cin>>L_Stat;
            cout<<"Enter the duration of the Loan: \n";
            cin>>Lduration;
            Myloan.setItemID(BookS_ID);
            Myloan.setDueTime(Lduration);
            Myloan.setLoanID(loaN_id);
            Myloan.setName(Person_name);
            Myloan.setNitems(Nmbr_bks);
            Myloan.setPatronID(PAt_id);
            Myloan.setStatus('n');
           // Myloan.setCurrentT(startT);
            Myloans.checkOutItem(Myloan);
        }
        if(choice==17){
            cout<<"\nCheck in a loan\n";
            cout<<"\nEnter the Loan id for the loan you want to delete:\n";
            cin>>loaN_id;
            cout<<"\nEnter how many items is the patron returning:\n";
            cin>>Nmbr_bks;
            Myloans.checkInItem(loaN_id,Nmbr_bks);

        }
        if(choice==18){
            cout<<"\nList all books for a specific patron based on patron id\n";
            cout<<"\n Enter the patron ID, for the patron Books info:\n";
            cin>>PAt_id;
            Myloans.listbooks_patron(PAt_id);
        }
        if(choice==19)
        {

            cout<<"\nEdit a loan\n";
            cout<<"To edit a loan enter the info for the loan\n";
            cout<<"Eter the id for the loan you want to edit "<<endl;
            cin>>loaN_id;
            check=Myloans.searchLoan(loaN_id);

            if(check!=-1)
            {
                cout<<"\nenter the person Name :\n";
                cin.ignore();
                getline(cin, Person_name);
                cout<<"\nEnter the new Loan id:\n";
                cin>>newLid;
                cout<<"\nEnter the new Patron Id number:\n";
                cin>>PAt_id;
                cout<<"Enter the new Number of books on this Loan:\n";
                cin>>Nmbr_bks;
                BookS_ID.resize(Nmbr_bks);
                cout<<"Enter the  new id for the books in the loan:\n";
                for(j=0;j<BookS_ID.size();j++)
                {
                cout<<"\nEnter the new id for book: "<<j+1<<" :\n";
                cin>>BookS_ID.at(j);
                }
                cout<<"\nEnter the status status of the loan as 'o' for overdue or as'n' for normal :\n";
                cin>>L_Stat;
                cout<<"Enter the duration of the Loan: \n";
                cin>>Lduration;
                Myloan.setItemID(BookS_ID);
                Myloan.setDueTime(Lduration);
                Myloan.setLoanID(newLid);
                Myloan.setName(Person_name);
                Myloan.setNitems(Nmbr_bks);
                Myloan.setPatronID(PAt_id);
                Myloan.setStatus(L_Stat);
                Myloans.editLoan(Myloan,check);
            }
            else
            {
                cout<<"\nLoan not found, Enter again\n";
            }
            
        }

        if(choice==20)
        {
            cout<<"\nReport Lost\n";
            cout<<"Enter the Lost Item id number:\n";
            cin>> Lostitem;
            check=libraryItems.searchInfo(Lostitem);
            if(check!=-1)
            {
                cout<<"Enter the ID of the patron who lost the book\n";
                cin>>Pat_IDn;
                Myloans.reportLost(Lostitem, Pat_IDn);
            }
            else
            {
                cout<<"\nItem was not found in the data base\n";
            }
            
        }

    }
    


 return 0;
}





    

        
         
        

       



