#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct Req
{
	string name, bricks, cement, paint;
};
struct Amnt
{
	int brick_am, cement_am, white_sand, brown_sand;
};
struct rate
{
	int brick_co, cement_co, wsand_co=300 , bsand_co=350, paint_co, ww=250;
};
struct dim_build
{	
	int length, breadth, height; double wall, roof, floor;
};
struct win_door
{
	dim_build wlen;
};
void display()
{
	system("cls");	cout<<"		   --------------------------------------"<<endl;	cout<<"		   |  Ahmed Constructions Private Ltd.  |"<<endl;	cout<<"		   --------------------------------------"<<endl;
	cout<<"\n	    Please be a bit logical and dont put any crazy data!"<<endl;	
}
int main()
{
	dim_build B;	
	rate C;			
	Req R;	
	Amnt A;	
	win_door W;
	int n, p=0, q=0, volume, win_ar=0, win_n, i, wall_ar_o, wall_ar_i;
	int total_cost, white=0, paint=0, bucket=1;
	float vol_b; char choose;
	display();
	cout<<"Enter your name: "; 	getline(cin, R.name);
	cout<<"Enter the Dimensions of your house: "<<endl;
	cout<<"Length (Ft):  ";	cin>>B.length;
	cout<<endl<<"Breadth (Ft): ";		cin>>B.breadth;
	cout<<endl<<"Height (Ft): "; 		cin>>B.height;
	cout<<endl<<"Thickness of the walls (In): "; cin>>B.wall;
	cout<<endl<<"Thickness of the floor (In): "; cin>>B.floor;
	cout<<endl<<"Thickness of the roof  (In): "; cin>>B.roof;
	B.roof *= 0.083; B.wall *= 0.083 ; B.floor *= 0.083;
	cout<<"Please choose the brand of Bricks you want (Choose the Number) : \n Each Brick will be (10 in x 1 in x 4 in) \n 1. Taj Bricks(Rs.8 Each) \n 2. Saathi Bricks(Rs.9 Each) \n 3. Samrat Bricks(Rs.10 Each)"<<endl;	cin>>n;
	switch(n)
	{
		case 1 :  { R.bricks="Taj Bricks"; C.brick_co=8; break; }
		case 2 :  { R.bricks="Saathi Bricks"; C.brick_co=9;	break; }
		case 3 :  {	R.bricks="Samrat Bricks";C.brick_co=10; break; }
		default: cout<<endl<<"You Chose an Invalid Option! Please Try again later!";
	}
	vol_b= (0.833 * 0.083 * 0.333 );
	cout<<"Please choose the brand of Cement you want (Choose the Number) : \n 1. Lafarge Cement(Rs.350 per Bag) \n 2. Birla Gold Cement(Rs.312 per Bag) \n 3. Konark Cement(Rs.300 per Bag) \n 4. Ambuja Cement(Rs.375 per Bag)"<<endl;	cin>>n;
	switch(n)
	{
		case 1 : {R.cement="Lafarge Cement"; C.cement_co=350; break; }
		case 2 : {R.cement="Brila Gold Cement"; C.cement_co=312;	break; }
		case 3 : {R.cement="Konark Cement"; C.cement_co=300;	break;	}
		case 4 : {R.cement="Ambuja Cement"; C.cement_co=375;	break;	}
	}
	cout<<"\nPlease enter the total number of cement bags: "; cin>>A.cement_am;
	cout<<"\nPlease enter the number of white sand rags: (Rs.350 per rag) "; cin>>A.white_sand;
	cout<<"\nPlease enter the number of brown sand rags: (Rs.300 per rag)"; cin>>A.brown_sand;
	volume = (B.length * B.breadth * B.height ) - ((B.length-B.wall)*(B.breadth-B.wall)*(B.height-(B.floor+B.roof)));
	display();
	cout<<"Please enter the number of windows you want: ";	cin>>win_n;
	for(i=0 ; i<win_n ; i++)
	{
		cout<<endl<<"Enter dimensions of window "<<i+1;
		cout<<endl<<"Length (Ft): ";	cin>>W.wlen.length;
		cout<<endl<<"Width (Ft): ";	cin>>W.wlen.breadth;
		win_ar += (i+1)*(W.wlen.length*W.wlen.breadth);
	}
	display();	cout<<endl<<"Please enter the number of doors you want: "; cin>>win_n;
	for(i=0 ; i<win_n ; i++)
	{
		cout<<endl<<"Enter dimensions of door "<<i+1;
		cout<<endl<<"Width (Ft): ";	cin>>W.wlen.length;
		cout<<endl<<"Height (Ft): ";	cin>>W.wlen.breadth;
		win_ar += (i+1)*(W.wlen.length*W.wlen.breadth);
	}
	volume = volume - (win_ar*B.wall);	A.brick_am = volume/vol_b;
	display();
	wall_ar_o = 2*((B.length*B.breadth)+(B.breadth*B.height)+(B.length*B.height)) - win_ar;
	wall_ar_i = 2*(((B.length-B.wall)*(B.breadth-B.wall))+((B.breadth-B.wall)*(B.height-B.floor-B.roof))+((B.length-B.wall)*(B.height-B.floor-B.roof)))- win_ar;
	cout<<"Do you want whitewash on your walls?"<<endl<<" Choose- YES(Y)/NO(N) ";	cin>>choose;
	switch(choose)
	{
		case 'N': cout<<"Thank you for your instructions."<<endl<<"You will not have any whitewash on your walls."; break;
		case 'Y': 
		{
			cout<<"Do you want Whitewash on both inner and outer walls?"<<endl<<" Select- BOTH(B)/INNER(I)/OUTER(O) (Case Sensitive) "; cin>>choose;
			switch(choose)
			{
				case 'B' : {white = C.ww*(wall_ar_o + wall_ar_i); break;}
				case 'I' : {white = C.ww*wall_ar_i; break;}
				case 'O' : {white = C.ww*wall_ar_o; break;}
				default: cout<<"You have given a wrong instruction! We will proceed with the available data."; break;
			}
			q=1; break;
		}
		default: cout<<"You have given a wrong instruction! We will proceed with the available data."; break;
	}
	cout<<endl<<"Enter any letter to continue: "; cin>>choose;
	display();
	cout<<"Do you want paint on your walls?"<<endl<<" Choose- YES(Y)/NO(N) ";	cin>>choose;
	switch(choose)
	{
		case 'N': cout<<"Thank you for your instructions."<<endl<<"You will not have any whitewash on your walls."; break;
		case 'Y': 
		{
			cout<<"Enter the brand of paint you want"<<endl<<"You will recieve pain in buckets (20L Capacity)"<<endl<<"1 Bucket can cover approximately 40 sq.ft. area"<<endl<<"Choose the Brand Number: \n 1. Nerolac Paints (Rs.2000) \n 2. Asian Paints (Rs.2500) \n 3. Indigo Paints (Rs.3000) \n 4. Berger Easy Paints (Rs.2750)"; cin>>n;
			switch(n)
				{
					case 1 : {R.paint="Nerolac Paints"; C.paint_co=2000; break; }
					case 2 : {R.paint="Asian Paints"; C.paint_co=2500;	break; }
					case 3 : {R.paint="Indigo Paints"; C.paint_co=3000;	break;	}
					case 4 : {R.paint="Berger Easy Paints"; C.paint_co=2750;	break;	}
				}
			cout<<"Do you want paint on both inner and outer walls?"<<endl<<" Select- BOTH(B)/INNER(I)/OUTER(O) (Case Sensitive) "; cin>>choose;
			switch(choose)
			{
				case 'B' : {bucket += (wall_ar_o+wall_ar_i)/40; paint=C.paint_co*bucket ;break;}
				case 'I' : {bucket += wall_ar_i/40; paint = C.paint_co*bucket; break;}
				case 'O' : {bucket += wall_ar_o/40; paint = C.paint_co*bucket; break;}
				default: cout<<"You have given a wrong instruction! We will proceed with the available data."; break;
			}
			p=1; break;
		}
		default: cout<<"You have given a wrong instruction! We will proceed with the available data."; break;
	}
	cout<<endl<<"Enter any letter to continue: "; cin>>choose;
	display();
	cout<<endl<<"Thank you for your valuable time, "<<R.name;
	total_cost = (A.cement_am*C.cement_co)+(A.white_sand*C.wsand_co)+(A.brown_sand*C.bsand_co) + white;
	cout<<endl<<"Your Chosen Brick Brand: "<<R.bricks<<endl<<"Your Chosen Cement Brand: "<<R.cement<<endl<<"Your Chosen Paint Brand: "<<R.paint;
	cout<<endl<<"As per your instructions,"<<endl<<"The total cost of the constructions will be Rs."<<total_cost;
	cout<<endl<<"For the construction, you need "<<A.brick_am+200<<" number of bricks."; cout<<endl<<"This amount of bricks will cost you Rs."<<(A.brick_am+200)*C.brick_co<<" more.";
	if(p==1)
	cout<<endl<<"Also, you will need "<<bucket<<" buckets of your desired paint."<<endl<<"This will cost you Rs."<<paint<<" more.";
	if(p==0)
	cout<<endl<<"You will not have any paint on your building's walls.";
	if(q==0)
	cout<<endl<<"Your walls will not have any white wash.";
}
