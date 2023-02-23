#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include"loans.h"
#include<ctime>
using namespace std;


int countofMov=0;
unsigned int m=0;
int Locate=0;
int movchecker=0;
int check=0;
int custid=0;
double CheckFines=0.0;
char rentingapprove;// a variable to make sure renting is ok



void Loans::checkout(Loan nloan){//remeber that the movie id is a vector, because the loan will have more than a movie wich every movie has diffrent id
    vloans.push_back(nloan);//add loan

    nloan.getCustomerID();
    movchecker=nloan.getNmovies();
    for(m=0; m <managecustomer.customers.size();m++)
    {
        
        // if statements for movies limit

        if(nloan.getCustomerID()==managecustomer.customers.at(m).GetId())
        {
            if((managecustomer.customers.at(m).GetActive()+movchecker)<=6)
            {
                countofMov=managecustomer.customers.at(m).GetActive();
                cout<<"number of movies is ok, renting is allowed\n";
                managecustomer.customers.at(m).SetActive(movchecker+countofMov);
                rentingapprove='y';
            }
            else
            {
                cout<<"number of movies is over the limit, renting Not allowed\n\n";
            }

        }
    }
        nloan.getMovieID();

    if(rentingapprove=='y')
    {
        for (m=0; m<moviemanage.mymovies.size();m++)
        {
            if(nloan.getMovieID().at(m)==moviemanage.mymovies.at(m)->getMovieID())
            {
                Locate = moviemanage.mymovies.at(m)->getMovieID();
                moviemanage.updateStatus(Locate,'o');
            }
        }
    }

}




void Loans::checkInmovie(int Checkloan, int moviesret)//delete a loan based on 
{
    Locate=0;
    Locate=this->search_l(Checkloan);
    int place=0;



    if(Locate!=1)
    {
         for (m=0; m<moviemanage.mymovies.size();m++)
        {
            if(vloans.at(Locate).getMovieID().at(m) == moviemanage.mymovies.at(m)->getMovieID())
            {
                place = moviemanage.mymovies.at(m)->getMovieID();    
                moviemanage.updateStatus(Locate,'i');
            }
        }

        for(m=0; m <managecustomer.customers.size();m++)
        {
            if(vloans.at(Locate).getCustomerID()==managecustomer.customers.at(m).GetId()){
                custid=managecustomer.customers.at(m).GetId();
                check=m;
            }
        }
            if(vloans.at(Locate).getLoanID()==Checkloan)
            {
            Checkloan= managecustomer.customers.at(check).GetFine();
            movchecker=abs(managecustomer.customers.at(check).GetActive()-moviesret);
            managecustomer.updatemovies_customer(custid, movchecker);
            }
            
        if(Checkloan>= 0)
        {
            cout<<"\nCustomer needs to pay: "<<Checkloan<<" $\n";
        }
       
    
     vloans.erase(vloans.begin()+Locate);


    }
    else
    {
        cout<<"Loan not found\n";
    }
    
}

 int Loans::search_l(int id_loan){

    for(m=0;m<vloans.size();m++){

        if(vloans.at(m).getLoanID()==id_loan){
            return m;
        }
    }
    return -1;


}

void Loans::listmovies_customer(int cust_id)
{
    for(m=0;0<vloans.size();m++)
    {
        if(vloans.at(m).getCustomerID()==cust_id)
        {
            Locate=m;
        }
    }
    Locate=-1;
    
    if(Locate!=-1)
    {
        for(m=0;0<moviemanage.mymovies.size();m++)
        {
            if(moviemanage.mymovies.at(m)->getMovieID() == vloans.at(Locate).getMovieID().at(m))
            {
                cout<<"\nMovie name is: " << moviemanage.mymovies.at(m).getTitle()<<endl;
                cout<<"\nMovie ID is: "<< moviemanage.mymovies.at(m).getMovieID();
                cout<<"\nMovie release date is: "<<moviemanage.mymovies.at(m).getReleasedate();
                cout<<"\nMovie rating is :"<<moviemanage.mymovies.at(m).getRating();
                cout<<"\nMovie rental cost is :"<<moviemanage.mymovies.at(m).getRentalcost();
                cout<<"\nMovie replacement cost:"<<moviemanage.mymovies.at(m).getReplacecost();
                cout<<"\nMovie duration is: "<<moviemanage.mymovies.at(m).getDuration();
                

                if(moviemanage.mymovies.at(m).getmoviestatus()=='i')
                {
                    cout<<"Movie status is: Avaliable\n";
                }

                if(moviemanage.mymovies.at(m).getmoviestatus()=='n')
                {
                    cout<<" Movie status is: Not avaliable\n";
                }

                if(moviemanage.mymovies.at(m).getmoviestatus()=='l')
                {
                    cout<<"Movie status is: Lost\n";
                }

                if(moviemanage.mymovies.at(m).getmoviestatus()=='r')
                {
                    cout<<"Movie status is: Overdue\n";
                }
            }
        }
    }
    else
    {
        cout<<"\nCustomer not found\n";
    }
    
    
}

// 

void Loans::editLoan(Loan editLoan, int fplace){
    vloans.at(fplace).setMovieID(editLoan.getMovieID());
    vloans.at(fplace).setDueTime(editLoan.getDueTime());
    vloans.at(fplace).setCustomerID(editLoan.getCustomerID());
    vloans.at(fplace).setLoanID(editLoan.getLoanID());
    vloans.at(fplace).setName(editLoan.getcusname());
    vloans.at(fplace).setNmovies(editLoan.getNmovies());
    vloans.at(fplace).setcurrentstatus(editLoan.getDueTime());


}
void Loans::reportLost( int lostMid, int Lost_personid ){
    
    for(m=0; m<moviemanage.mymovies.size();m++)
    {
        if(moviemanage.mymovies.at(m)->getMovieID()==lostMid)
        {
            cout<<"Movie Found\n";
            // Moviemanage
            moviemanage.mymovies.at(m)->setmoviestatus('l');
            movchecker=moviemanage.mymovies.at(m)->getRentalcost();
        }
    }
    
    for(m=0; m<managecustomer.customers.size(); m++)
    {
        if(managecustomer.customers.at(m).GetId()==Lost_personid)
        {
            managecustomer.customers.at(m).SetFine(movchecker);
        }
    }
    
    

    
}
void Loans::listOverdues(int systemtime){
    for(m=0;m<vloans.size();m++)
    {
        if((vloans.at(m).getcurrentTime()+vloans.at(m).getDueTime())>=systemtime){

        }
    }
}


        


