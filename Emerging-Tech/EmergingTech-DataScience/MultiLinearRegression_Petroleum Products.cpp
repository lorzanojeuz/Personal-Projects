#include<iostream>
#include<iomanip>
#include<cmath>
#include <stdio.h>
#include<bits/stdc++.h>


using namespace std;


int quit(){
	system("cls");
	cout<<"\t\t\t\t\t\t  ------------------"<<endl;
	cout<<"\t\t\t\t\t\t  >>>>THANK YOU!<<<<"<<endl;
	cout<<"\t\t\t\t\t\t  ------------------"<<endl;
	exit(0);
}


int ron95_week(){
	int i;
    double b0,b1,b2,n;
	double x1[44] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,			// x1-values(TIME)
					27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44};			
						
    double x2[44] = {28.76,30.13,32.47,32.44,33.51,34.44,35.08,36.11,36.58,46.64,40.80,41.97,		// x2-values(CRUDE OIL)
					41.80,39.16,36.90,40.75,37.58,40.62,41.47,41.68,42.73,45.31,44.15,44.44,
					42.71,42.31,42.10,40.09,40.04,39.13,39.32,37.11,36.84,36.35,38.61,36.46,
					35.90,35.06,32.96,33.92,36.50,33.94,33.94,34.31};
																				
    double y[44] = {64.4,58.45,66.05,63.35,64.1,62.3,66.35,65.05,65.95,69.55,76.65,71.2,			// y-values(COST)
					74.6,72.3,71.3,71.75,74.75,74.1,78.3,77.9,81.85,80.15,82.85,85,85.8,
					86.30,86.3,80.6,75.6,75.2,75.95,73.85,72.85,73.55,74.95,72.35,71.9,68.3,
					67.20,66.8,68,68.8,68.45,68.2};  
        
    double x1mean=0,x2mean=0,ymean=0,x1s=0,x2s=0,ys=0,x1sum=0,x2sum=0,x1ysum=0,x2ysum=0,		//variables for sigma,mean,sums
		  x1x2sum,x1fin=0,x2fin=0,x1yfin=0,x2yfin=0,x1x2fin=0, x1x1sum=0,x2x2sum=0,x1x1=0,
		  x2x2=0,x1y=0, x2y=0,x1x2=0;  
		                											 
    for (i=0;i<44;i++)
    {
        //multiple linear
        //sigma
        x1s+=x1[i];                       		//calculate x1i
        x2s+=x2[i];                        		//calculate x2i
        ys+=y[i];								//calculate yi
        x1x1+=x1[i]*x1[i];						//calculate x1x1
        x2x2+=x2[i]*x2[i];						//calculate x2x2
        x1x2+=x1[i]*x2[i];						//calculate x1x2
        x1y+=x1[i]*y[i];						//calculate x1y
        x2y+=x2[i]*y[i];						//calculate x2y
        
        //mean
        x1mean=x1s/44;							//calculate mean of x1
        x2mean=x2s/44;							//calculate mean of x2
        ymean=ys/44;							//calculate mean of y
        
        //calculate regression sums
        x1fin=x1x1-pow(x1s,2)/44;					//Regular sum of x1^2
        x2fin=x2x2-pow(x2s,2)/44;					//regular sum of x2^2
        x1yfin=x1y-((x1s*ys)/44);					//regular sum of x1y
        x2yfin=x2y-((x2s*ys)/44);					//regular sum of x2y
        x1x2fin=x1x2-((x1s*x2s)/44);				//regular sum of x1x2    	
    }
    
    b1= (x2fin*x1yfin-x1x2fin*x2yfin)/(x1fin*x2fin-pow(x1x2fin,2));         //calculate b1
    b2=(x1fin*x2yfin-x1x2fin*x1yfin)/(x1fin*x2fin-pow(x1x2fin,2));         	//calculate b2
    b0= ymean-(b1*x1mean)-(b2*x2mean);										//calculate b0
    
	double y_fit[44];                        //an array to store the new fitted values of y    
    
	for (i=0;i<44;i++)
        y_fit[i]=b0+(b1*x1[i])+(b2*x2[i]);                    //to calculate y(fitted) at given x points
    	cout<<"\t\t\t\t\t\t    Dataset of RON95"<<endl;  
		cout<<"\t\t\t\t\t\t  January-October 2022"<<endl;  	
		cout<<"\t\t\t--------------------------------------------------------------------------\n";
    	cout<<"\t\t\t|"<<setw(7)<<"Weeks"<<setw(13)<<"Crude oil"<<setw(25)<<"RON95 Price(Actual)"<<setw(28)<<"RON95 Price(Predicted) |"<<endl;
    	cout<<"\t\t\t--------------------------------------------------------------------------\n";
    
	for (i=0;i<44;i++)
    	cout<<"\t\t\t|"<<setw(5)<<x1[i]<<setw(13)<<x2[i]<<setw(20)<<y[i]<<setw(28)<<y_fit[i]<<"      |"<<endl;		//print a table 
    	cout<<"\t\t\t--------------------------------------------------------------------------\n";	
	 
    double week,oil;
		cout<<"\nPlease enter the week you want to predict: ";
			while(true){
   				cin>>week;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter the week you want to predict: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\nPlease enter a specific price for crude oil: ";
			while(true){
   				cin>>oil;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter a specific price for crude oil: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t|  Multiple linear regression equation  |"<<endl;
   		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t   The equation of the best fit is:\n\n"<<"\t\t\t\t\t y = "<< b0 <<" + "<<b1 <<"x1 "<<" + "<<b2<<"x2"<<endl<<endl;        //print the best fit
	char ag;
   	double predy= b0+(b1*week)+(b2*oil); 
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		cout<<"\t\t\t       The Predicted price of RON95 in week "<<week<<" is: "<<predy<<" PHP     "<<endl;
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		start:
   		cout<<"Do you want to predict again?"<<endl;
   		cout<<"Enter (y/n):";
   		cin>>ag;
   	if (ag == 'y'){
   	system("cls");
	}
	else if(ag =='n'){
		quit();
		
	}
	else{
		cout<<"Invalid input"<<endl;
		goto start;
	}
}

int ron95_month(){
	int i;
    double b0,b1,b2,n;
	double x1[11] = {1,2,3,4,5,6,7,8,9,10,11};			
						
    double x2[11] = {32.44,36.11,41.80,37.58,42.73,42.31,39.13,36.35,32.96,33.94,34.31};
																				
    double y[11] = {63.35,65.05,74.6,74.75,81.85,86.3,75.2,73.55,67.2,68.45,68.2};  
        
    double x1mean=0,x2mean=0,ymean=0,x1s=0,x2s=0,ys=0,x1sum=0,x2sum=0,x1ysum=0,x2ysum=0,		//variables for sigma,mean,sums
		  x1x2sum,x1fin=0,x2fin=0,x1yfin=0,x2yfin=0,x1x2fin=0, x1x1sum=0,x2x2sum=0,x1x1=0,
		  x2x2=0,x1y=0, x2y=0,x1x2=0;  
		                											 
    for (i=0;i<11;i++)
    {
        //multiple linear
        //sigma
        x1s+=x1[i];                       		//calculate x1i
        x2s+=x2[i];                        		//calculate x2i
        ys+=y[i];								//calculate yi
        x1x1+=x1[i]*x1[i];						//calculate x1x1
        x2x2+=x2[i]*x2[i];						//calculate x2x2
        x1x2+=x1[i]*x2[i];						//calculate x1x2
        x1y+=x1[i]*y[i];						//calculate x1y
        x2y+=x2[i]*y[i];						//calculate x2y
        
        //mean
        x1mean=x1s/11;							//calculate mean of x1
        x2mean=x2s/11;							//calculate mean of x2
        ymean=ys/11;							//calculate mean of y
        
        //calculate regression sums
        x1fin=x1x1-pow(x1s,2)/11;					//Regular sum of x1^2
        x2fin=x2x2-pow(x2s,2)/11;					//regular sum of x2^2
        x1yfin=x1y-((x1s*ys)/11);					//regular sum of x1y
        x2yfin=x2y-((x2s*ys)/11);					//regular sum of x2y
        x1x2fin=x1x2-((x1s*x2s)/11);				//regular sum of x1x2    	
    }
    
    b1= (x2fin*x1yfin-x1x2fin*x2yfin)/(x1fin*x2fin-pow(x1x2fin,2));         //calculate b1
    b2=(x1fin*x2yfin-x1x2fin*x1yfin)/(x1fin*x2fin-pow(x1x2fin,2));         	//calculate b2
    b0= ymean-(b1*x1mean)-(b2*x2mean);										//calculate a
    
	double y_fit[11];                        //an array to store the new fitted values of y    
    
	for (i=0;i<11;i++)
        y_fit[i]=b0+(b1*x1[i])+(b2*x2[i]);                    //to calculate y(fitted) at given x points
        
    	cout<<"\t\t\t\t\t\t    Dataset of RON95"<<endl;  
		cout<<"\t\t\t\t\t\t  January-November 2022"<<endl;  	
		cout<<"\t\t\t--------------------------------------------------------------------------\n";
    	cout<<"\t\t\t|"<<setw(7)<<"Months"<<setw(13)<<"Crude oil"<<setw(25)<<"RON95 Price(Actual)"<<setw(28)<<"RON95 Price(Predicted) |"<<endl;
    	cout<<"\t\t\t--------------------------------------------------------------------------\n";
    
	for (i=0;i<11;i++)
    	cout<<"\t\t\t|"<<setw(5)<<x1[i]<<setw(13)<<x2[i]<<setw(20)<<y[i]<<setw(28)<<y_fit[i]<<"      |"<<endl;		//print a table 
    	cout<<"\t\t\t--------------------------------------------------------------------------\n";	
	 
    double month,oil;
   		cout<<"Please enter the month you want to predict: ";
			while(true){
   				cin>>month;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter the month you want to predict: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\nPlease enter a specific price for crude oil: ";
			while(true){
   				cin>>oil;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter a specific price for crude oil: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t|  Multiple linear regression equation  |"<<endl;
   		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t   The equation of the best fit is:\n\n"<<"\t\t\t\t\t y = "<< b0 <<" + "<<b1 <<"x1 "<<" + "<<b2<<"x2"<<endl<<endl;        //print the best fit
	char ag;
   	double predy= b0+(b1*month)+(b2*oil); 
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		cout<<"\t\t\t       The Predicted price of RON95 in month "<<month<<" is: "<<predy<<" PHP   "<<endl;
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		start:
   		cout<<"Do you want to predict again?"<<endl;
   		cout<<"Enter (y/n):";
   		cin>>ag;
   	if (ag == 'y'){
   	system("cls");
	}
	else if(ag =='n'){
		quit();
	}
	else{
		cout<<"Invalid input"<<endl;
		goto start;
	}
}

int diesel_week(){
	int i;
    double b0,b1,b2,n;
	double x1[44] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,			// x1-values(TIME)
					27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44};			
						
    double x2[44] = {28.76,30.13,32.47,32.44,33.51,34.44,35.08,36.11,36.58,46.64,40.80,41.97,		// x2-values(CRUDE OIL)
					41.80,39.16,36.90,40.75,37.58,40.62,41.47,41.68,42.73,45.31,44.15,44.44,
					42.71,42.31,42.10,40.09,40.04,39.13,39.32,37.11,36.84,36.35,38.61,36.46,
					35.90,35.06,32.96,33.92,36.50,33.94,33.94,34.31};
																				
    double y[44] = {51.47,46.5,54.37,56.27,51.3,58.22,59.27,57.45,56.45,62.3,75.45,64,72.65,70.8,70.45,72.15,76.25,75.1,			// y-values(COST)
					79.3,76.2,73.9,75.1,81.65,85.95,89.05,90.7,87.7,81.6,79.6,77.75,74.9,72.7,71.65,74.25,81.5,79.95,77.35,
					73.2,71.7,71.25,78.1,80.8,79.7,79.1}; 
        
    double x1mean=0,x2mean=0,ymean=0,x1s=0,x2s=0,ys=0,x1sum=0,x2sum=0,x1ysum=0,x2ysum=0,		//variables for sigma,mean,sums
		  x1x2sum,x1fin=0,x2fin=0,x1yfin=0,x2yfin=0,x1x2fin=0, x1x1sum=0,x2x2sum=0,x1x1=0,
		  x2x2=0,x1y=0, x2y=0,x1x2=0;  
		                											 
    for (i=0;i<44;i++)
    {
        //multiple linear
        //sigma
        x1s+=x1[i];                       		//calculate x1i
        x2s+=x2[i];                        		//calculate x2i
        ys+=y[i];								//calculate yi
        x1x1+=x1[i]*x1[i];						//calculate x1x1
        x2x2+=x2[i]*x2[i];						//calculate x2x2
        x1x2+=x1[i]*x2[i];						//calculate x1x2
        x1y+=x1[i]*y[i];						//calculate x1y
        x2y+=x2[i]*y[i];						//calculate x2y
        
        //mean
        x1mean=x1s/44;							//calculate mean of x1
        x2mean=x2s/44;							//calculate mean of x2
        ymean=ys/44;							//calculate mean of y
        
        //calculate regression sums
        x1fin=x1x1-pow(x1s,2)/44;					//Regular sum of x1^2
        x2fin=x2x2-pow(x2s,2)/44;					//regular sum of x2^2
        x1yfin=x1y-((x1s*ys)/44);					//regular sum of x1y
        x2yfin=x2y-((x2s*ys)/44);					//regular sum of x2y
        x1x2fin=x1x2-((x1s*x2s)/44);				//regular sum of x1x2    	
    }
    
    b1= (x2fin*x1yfin-x1x2fin*x2yfin)/(x1fin*x2fin-pow(x1x2fin,2));         //calculate b1
    b2=(x1fin*x2yfin-x1x2fin*x1yfin)/(x1fin*x2fin-pow(x1x2fin,2));         	//calculate b2
    b0= ymean-(b1*x1mean)-(b2*x2mean);										//calculate a
    
	double y_fit[44];                        //an array to store the new fitted values of y    
    
	for (i=0;i<44;i++)
        y_fit[i]=b0+(b1*x1[i])+(b2*x2[i]);                    //to calculate y(fitted) at given x points
        
    	cout<<"\t\t\t\t\t\t    Dataset of Diesel"<<endl;
		cout<<"\t\t\t\t\t\t  January-November 2022"<<endl;  	
		cout<<"\t\t\t----------------------------------------------------------------------------\n";
    	cout<<"\t\t\t|"<<setw(7)<<"Weeks"<<setw(13)<<"Crude oil"<<setw(27)<<"Diesel Price(Actual)"<<setw(28)<<"Diesel Price(Predicted) |"<<endl;
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";
    
	for (i=0;i<44;i++)
    	cout<<"\t\t\t|"<<setw(5)<<x1[i]<<setw(13)<<x2[i]<<setw(20)<<y[i]<<setw(28)<<y_fit[i]<<"        |"<<endl;		//print a table 
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";	
	 
    double week,oil;
   		cout<<"Please enter the week you want to predict: ";
			while(true){
   				cin>>week;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter the week you want to predict: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\nPlease enter a specific price for crude oil: ";
			while(true){
   				cin>>oil;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter a specific price for crude oil: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t|  Multiple linear regression equation  |"<<endl;
   		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t   The equation of the best fit is:\n\n"<<"\t\t\t\t\t y = "<< b0 <<" + "<<b1 <<"x1 "<<" + "<<b2<<"x2"<<endl<<endl;        //print the best fit
	char ag;
   	double predy= b0+(b1*week)+(b2*oil); 
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		cout<<"\t\t\t       The Predicted price of Diesel in week "<<week<<" is: "<<predy<<" PHP    "<<endl;
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		start:
   		cout<<"Do you want to predict again?"<<endl;
   		cout<<"Enter (y/n):";
   		cin>>ag;
   	if (ag == 'y'){
   	system("cls");
	}
	else if(ag =='n'){
		quit();
	}
	else{
		cout<<"Invalid input"<<endl;
		goto start;
	}
}
int diesel_month(){
	int i;
    double b0,b1,b2,n;
	double x1[11] = {1,2,3,4,5,6,7,8,9,10,11};			
						
    double x2[11] = {32.44,36.11,41.80,37.58,42.73,42.31,39.13,36.35,32.96,33.94,34.31};
																				
    double y[11] = {56.27,57.45,72.65,76.25,73.9,90.7,77.75,74.25,71.7,79.7,79.1}; 
        
    double x1mean=0,x2mean=0,ymean=0,x1s=0,x2s=0,ys=0,x1sum=0,x2sum=0,x1ysum=0,x2ysum=0,		//variables for sigma,mean,sums
		  x1x2sum,x1fin=0,x2fin=0,x1yfin=0,x2yfin=0,x1x2fin=0, x1x1sum=0,x2x2sum=0,x1x1=0,
		  x2x2=0,x1y=0, x2y=0,x1x2=0;  
		                											 
    for (i=0;i<11;i++)
    {
        //multiple linear
        //sigma
        x1s+=x1[i];                       		//calculate x1i
        x2s+=x2[i];                        		//calculate x2i
        ys+=y[i];								//calculate yi
        x1x1+=x1[i]*x1[i];						//calculate x1x1
        x2x2+=x2[i]*x2[i];						//calculate x2x2
        x1x2+=x1[i]*x2[i];						//calculate x1x2
        x1y+=x1[i]*y[i];						//calculate x1y
        x2y+=x2[i]*y[i];						//calculate x2y
        
        //mean
        x1mean=x1s/11;							//calculate mean of x1
        x2mean=x2s/11;							//calculate mean of x2
        ymean=ys/11;							//calculate mean of y
        
        //calculate regression 
        x1fin=x1x1-pow(x1s,2)/11;					// x1^2
        x2fin=x2x2-pow(x2s,2)/11;					// x2^2
        x1yfin=x1y-((x1s*ys)/11);					// x1y
        x2yfin=x2y-((x2s*ys)/11);					// x2y
        x1x2fin=x1x2-((x1s*x2s)/11);				// x1x2    	
    }
    
    b1= (x2fin*x1yfin-x1x2fin*x2yfin)/(x1fin*x2fin-pow(x1x2fin,2));         //calculate b1
    b2=(x1fin*x2yfin-x1x2fin*x1yfin)/(x1fin*x2fin-pow(x1x2fin,2));         	//calculate b2
    b0= ymean-(b1*x1mean)-(b2*x2mean);										//calculate a
    
	double y_fit[11];                        //an array to store the new fitted values of y    
    
	for (i=0;i<11;i++)
        y_fit[i]=b0+(b1*x1[i])+(b2*x2[i]);                    //to calculate y(fitted) at given x points
        
    	cout<<"\t\t\t\t\t\t    Dataset of Diesel"<<endl;
		cout<<"\t\t\t\t\t\t  January-November 2022"<<endl;  	
		cout<<"\t\t\t----------------------------------------------------------------------------\n";
    	cout<<"\t\t\t|"<<setw(7)<<"Months"<<setw(13)<<"Crude oil"<<setw(27)<<"Diesel Price(Actual)"<<setw(28)<<"Diesel Price(Predicted) |"<<endl;
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";
    
	for (i=0;i<11;i++)
    	cout<<"\t\t\t|"<<setw(5)<<x1[i]<<setw(13)<<x2[i]<<setw(20)<<y[i]<<setw(28)<<y_fit[i]<<"        |"<<endl;		//print a table 
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";	
	 
    double month,oil;
   		cout<<"Please enter the month you want to predict: ";
			while(true){
   				cin>>month;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter the month you want to predict: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\nPlease enter a specific price for crude oil: ";
			while(true){
   				cin>>oil;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter a specific price for crude oil: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t|  Multiple linear regression equation  |"<<endl;
   		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t   The equation of the best fit is:\n\n"<<"\t\t\t\t\t y = "<< b0 <<" + "<<b1 <<"x1 "<<" + "<<b2<<"x2"<<endl<<endl;        //print the best fit
	char ag;
   	double predy= b0+(b1*month)+(b2*oil); 
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		cout<<"\t\t\t       The Predicted price of Diesel in month "<<month<<" is: "<<predy<<" PHP   "<<endl;
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		start:
   		cout<<"Do you want to predict again?"<<endl;
   		cout<<"Enter (y/n):";
   		cin>>ag;
   	if (ag == 'y'){
   	system("cls");
	}
	else if(ag =='n'){
		quit();
	}
	else{
		cout<<"Invalid input"<<endl;
		goto start;
	}
}

int kerosene_week(){
	int i;
    double b0,b1,b2,n;
	double x1[44] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,			// x1-values(TIME)
					27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44};			
						
    double x2[44] = {28.76,30.13,32.47,32.44,33.51,34.44,35.08,36.11,36.58,46.64,40.80,41.97,		// x2-values(CRUDE OIL)
					41.80,39.16,36.90,40.75,37.58,40.62,41.47,41.68,42.73,45.31,44.15,44.44,
					42.71,42.31,42.10,40.09,40.04,39.13,39.32,37.11,36.84,36.35,38.61,36.46,
					35.90,35.06,32.96,33.92,36.50,33.94,33.94,34.31};
																				
    double y[44] = {53.62,53.86,56.1,58.12,60.23,60.75,60.96,63.01,61.78,66.44,74.98,66.34,71.45,
    				74.23,71.34,72.56,78.05,78.43,81.04,77.84,76.01,80.45,87.24,92.24,93.05,94.14,
					89.76,85.07,85.05,82.35,82.35,80.1,77.04,81.34,84.01,87.94,84.65,80.21,78.93,
					77.54,81.95,84.71,85.37,84.16}; 
        
    double x1mean=0,x2mean=0,ymean=0,x1s=0,x2s=0,ys=0,x1sum=0,x2sum=0,x1ysum=0,x2ysum=0,		//variables for sigma,mean,sums
		  x1x2sum,x1fin=0,x2fin=0,x1yfin=0,x2yfin=0,x1x2fin=0, x1x1sum=0,x2x2sum=0,x1x1=0,
		  x2x2=0,x1y=0, x2y=0,x1x2=0;  
		                											 
    for (i=0;i<44;i++)
    {
        //multiple linear
        //sigma
        x1s+=x1[i];                       		//calculate x1i
        x2s+=x2[i];                        		//calculate x2i
        ys+=y[i];								//calculate yi
        x1x1+=x1[i]*x1[i];						//calculate x1x1
        x2x2+=x2[i]*x2[i];						//calculate x2x2
        x1x2+=x1[i]*x2[i];						//calculate x1x2
        x1y+=x1[i]*y[i];						//calculate x1y
        x2y+=x2[i]*y[i];						//calculate x2y
        
        //mean
        x1mean=x1s/44;							//calculate mean of x1
        x2mean=x2s/44;							//calculate mean of x2
        ymean=ys/44;							//calculate mean of y
        
        //calculate regression sums
        x1fin=x1x1-pow(x1s,2)/44;					//Regular sum of x1^2
        x2fin=x2x2-pow(x2s,2)/44;					//regular sum of x2^2
        x1yfin=x1y-((x1s*ys)/44);					//regular sum of x1y
        x2yfin=x2y-((x2s*ys)/44);					//regular sum of x2y
        x1x2fin=x1x2-((x1s*x2s)/44);				//regular sum of x1x2    	
    }
    
    b1= (x2fin*x1yfin-x1x2fin*x2yfin)/(x1fin*x2fin-pow(x1x2fin,2));         //calculate b1
    b2=(x1fin*x2yfin-x1x2fin*x1yfin)/(x1fin*x2fin-pow(x1x2fin,2));         	//calculate b2
    b0= ymean-(b1*x1mean)-(b2*x2mean);										//calculate a
    
	double y_fit[44];                        //an array to store the new fitted values of y    
    
	for (i=0;i<44;i++)
        y_fit[i]=b0+(b1*x1[i])+(b2*x2[i]);                    //to calculate y(fitted) at given x points
       
    	cout<<"\t\t\t\t\t\t    Dataset of Kerosene"<<endl;
		cout<<"\t\t\t\t\t\t   January-November 2022"<<endl;  	
		cout<<"\t\t\t----------------------------------------------------------------------------\n";
    	cout<<"\t\t\t|"<<setw(7)<<"Weeks"<<setw(13)<<"Crude oil"<<setw(27)<<"Kerosene Price(Actual)"<<setw(28)<<"Kerosene Price(Predicted) |"<<endl;
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";
    
	for (i=0;i<44;i++)
    	cout<<"\t\t\t|"<<setw(5)<<x1[i]<<setw(13)<<x2[i]<<setw(20)<<y[i]<<setw(28)<<y_fit[i]<<"        |"<<endl;		//print a table 
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";	
	 
    double week,oil;
   		cout<<"Please enter the week you want to predict: ";
   			while(true){
   				cin>>week;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter the week you want to predict: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\nPlease enter a specific price for crude oil: ";
			while(true){
   				cin>>oil;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter a specific price for crude oil: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t|  Multiple linear regression equation  |"<<endl;
   		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t   The equation of the best fit is:\n\n"<<"\t\t\t\t\t y = "<< b0 <<" + "<<b1 <<"x1 "<<" + "<<b2<<"x2"<<endl<<endl;        //print the best fit
   	
	char ag;
   	double predy= b0+(b1*week)+(b2*oil); 
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		cout<<"\t\t\t       The Predicted price of Kerosene in week "<<week<<" is: "<<predy<<" PHP "<<endl;
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		start:
   		cout<<"Do you want to predict again?"<<endl;
   		cout<<"Enter (y/n):";
   		cin>>ag;
   	if (ag == 'y'){
   	system("cls");
	}
	else if(ag =='n'){
		quit();
	}
	else{
		cout<<"Invalid input"<<endl;
		goto start;
	}
}

int kerosene_month(){
	int i;
    double b0,b1,b2,n;
	double x1[11] = {1,2,3,4,5,6,7,8,9,10,11};			
						
    double x2[11] = {32.44,36.11,41.80,37.58,42.73,42.31,39.13,36.35,32.96,33.94,34.31};
																				
    double y[11] = {58.12,63.01,71.45,78.05,76.01,94.14,82.35,81.34,78.93,85.37,84.16}; 
        
    double x1mean=0,x2mean=0,ymean=0,x1s=0,x2s=0,ys=0,x1sum=0,x2sum=0,x1ysum=0,x2ysum=0,		//variables for sigma,mean,sums
		  x1x2sum,x1fin=0,x2fin=0,x1yfin=0,x2yfin=0,x1x2fin=0, x1x1sum=0,x2x2sum=0,x1x1=0,
		  x2x2=0,x1y=0, x2y=0,x1x2=0;  
		                											 
    for (i=0;i<11;i++)
    {
        //multiple linear
        //sigma
        x1s+=x1[i];                       		//calculate x1i
        x2s+=x2[i];                        		//calculate x2i
        ys+=y[i];								//calculate yi
        x1x1+=x1[i]*x1[i];						//calculate x1x1
        x2x2+=x2[i]*x2[i];						//calculate x2x2
        x1x2+=x1[i]*x2[i];						//calculate x1x2
        x1y+=x1[i]*y[i];						//calculate x1y
        x2y+=x2[i]*y[i];						//calculate x2y
        
        //mean
        x1mean=x1s/11;							//calculate mean of x1
        x2mean=x2s/11;							//calculate mean of x2
        ymean=ys/11;							//calculate mean of y
        
        //calculate regression sums
        x1fin=x1x1-pow(x1s,2)/11;					//Regular sum of x1^2
        x2fin=x2x2-pow(x2s,2)/11;					//regular sum of x2^2
        x1yfin=x1y-((x1s*ys)/11);					//regular sum of x1y
        x2yfin=x2y-((x2s*ys)/11);					//regular sum of x2y
        x1x2fin=x1x2-((x1s*x2s)/11);				//regular sum of x1x2    	
    }
    
    b1= (x2fin*x1yfin-x1x2fin*x2yfin)/(x1fin*x2fin-pow(x1x2fin,2));         //calculate b1
    b2=(x1fin*x2yfin-x1x2fin*x1yfin)/(x1fin*x2fin-pow(x1x2fin,2));         	//calculate b2
    b0= ymean-(b1*x1mean)-(b2*x2mean);										//calculate a
    
	double y_fit[11];                        //an array to store the new fitted values of y    
    
	for (i=0;i<11;i++)
        y_fit[i]=b0+(b1*x1[i])+(b2*x2[i]);                    //to calculate y(fitted) at given x points
        
    	cout<<"\t\t\t\t\t\t    Dataset of Kerosene"<<endl;
		cout<<"\t\t\t\t\t\t   January-November 2022"<<endl;  	
		cout<<"\t\t\t----------------------------------------------------------------------------\n";
    	cout<<"\t\t\t|"<<setw(7)<<"Months"<<setw(13)<<"Crude oil"<<setw(27)<<"Kerosene Price(Actual)"<<setw(28)<<"Kerosene Price(Predicted) |"<<endl;
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";
    
	for (i=0;i<11;i++)
    	cout<<"\t\t\t|"<<setw(5)<<x1[i]<<setw(13)<<x2[i]<<setw(20)<<y[i]<<setw(28)<<y_fit[i]<<"        |"<<endl;		//print a table 
    	cout<<"\t\t\t----------------------------------------------------------------------------\n";	
	 
    double month,oil;
   		cout<<"Please enter the month you want to predict: ";
   			while(true){
   				cin>>month;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter the month you want to predict: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\nPlease enter a specific price for crude oil: ";
			while(true){
   				cin>>oil;
   					if(!cin){
   						cin.clear();
        				cin.ignore(numeric_limits<streamsize>::max(), '\n');
        				cout << "Invalid input " << endl;
        				cout<<"\nPlease enter a specific price for crude oil: ";
        				continue;
			   }
   			else break;
			   }
		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t|  Multiple linear regression equation  |"<<endl;
   		cout<<"\t\t\t\t\t+---------------------------------------+"<<endl;
   		cout<<"\t\t\t\t\t   The equation of the best fit is:\n\n"<<"\t\t\t\t\t y = "<< b0 <<" + "<<b1 <<"x1 "<<" + "<<b2<<"x2"<<endl<<endl;        //print the best fit
   	
	char ag;
   	double predy= b0+(b1*month)+(b2*oil); 
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		cout<<"\t\t\t      The Predicted price of Kerosene in month "<<month<<" is: "<<predy<<" PHP "<<endl;
   		cout<<"\t\t\t    +--------------------------------------------------------------+"<<endl;
   		start:
   		cout<<"Do you want to predict again?"<<endl;
   		cout<<"Enter (y/n):";
   		cin>>ag;
   	if (ag == 'y'){
   	system("cls");
	}
	else if(ag =='n'){
		quit();
	}
	else{
		cout<<"Invalid input"<<endl;
		goto start;
	}
}
   	 

int main(){
	
	system("cls");
	system("color 70");
	int x=0;
	while (1){
	cout<<"\t\t\t\t                 Group 6- Meta-Four"<<endl<<endl;
    cout<<"\t\t\t\t  +---------------------------------------------------+\n";
	cout<<"\t\t\t\t  |          Choose from the options below:           |\n";
	cout<<"\t\t\t\t  |                                                   |\n";
	cout<<"\t\t\t\t  |      [1] RON95   (Week)    [4] RON95   (Month)    |\n";
	cout<<"\t\t\t\t  |      [2] Diesel  (Week)    [5] Diesel  (Month)    |\n";
	cout<<"\t\t\t\t  |      [3] Kerosene(Week)    [6] Kerosene(Month)    |\n";
	cout<<"\t\t\t\t  |                            [7]Exit                |\n";
	cout<<"\t\t\t\t  *---------------------------------------------------*\n";
	start:
	cout<<"\nEnter your choice (1-7): ";
	cin>>x;
	
	if(x==1){
	system("cls");
		ron95_week();
	}		
	else if(x==2){
	system("cls");
		diesel_week();
	}
	else if(x==3){
	system("cls");
		kerosene_week();
	}
	else if(x==4){
	system("cls");
		ron95_month();
	}
	else if(x==5){
	system("cls");
		diesel_month();
	}
	else if(x==6){
	system("cls");
		kerosene_month();
	}
	else if(x==7){
		quit();
		return 0;
	}
	else{
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input " << endl;
		goto start;
	}
  }
}

	

	



	




















