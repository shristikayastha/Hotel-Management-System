#include<iostream>
using namespace std;
class Hotel{
private:
struct  Node{
int id;
string date;
string name,roomtype;
Node*next;
};
public:
Node*head=NULL;
void insert();
void menu();
void update();
void search();
void del();
void sort();
void show();
};
void Hotel::menu(){
int choice;
do{
cout<<"\n"<<endl;
cout<<"\t------------WELCOME TO HOTEL MANAGEMENT SYSTEM-----------\n "<<endl;
cout<<"\n\t------------------HOTEL MANAGEMENT SYSTEM------------------";
cout<<"\n\n S.NO  FUNCTIONS          DESCRIPTION     "<<endl;
cout<<"\n1\t\tAllocate Room\t\tInsert New Room";
cout<<"\n2\t\tSearch Room\t\t\tSearch Room with Room Id";
cout<<"\n3\t\tUpdate Room\t\t\tUpdate  Room Record";
cout<<"\n4\t\tDelete Room\t\t\t Delete Room with  Room Id";
cout<<"\n5\t\tShow  Room Record\tShow Room Records that(we added)";
cout<<"\n6\t\tExit"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>choice;
switch(choice){
case 1:
insert();
break;
case 2:
search();
break;
case 3:
update();
break;
case 4:
del();
break;
case 5:
sort();
show();
break;
default:
cout<<"INVALID";
break;
}
}while(choice!=6);
}
void Hotel::insert(){
cout<<"\n\t---------------HOTEL MANAGEMENT SYSTEM--------------\n";
Node*newNode=new Node;
cout<<"Enter Room ID:"<<endl;
cin>>newNode->id;
cout<<"Enter Customer Name:"<<endl;
cin>>newNode->name;
cout<<"Enter Allocated Date:(YYYY-MM-DD)"<<endl;
cin>>newNode->date;
cout<<"Enter Room Type(single/double/deluxe):"<<endl;
cin>>newNode->roomtype;
newNode->next=NULL;
if(head==NULL){
head=newNode;
}
else{
Node*ptr=head;
while(ptr->next!=NULL){
ptr=ptr->next;
}
ptr->next= newNode;
 }
cout<<"\n\n\t\t New  Room Inserted";
}
void Hotel::search(){
cout<<"\n\t---------------------HOTEL MANAGEMENT SYSTEM------------------\n";
int  t_id;
if(head==NULL){
cout<<"\n\n Linked list is Empty";
}
else{
cout<<"\n\nRoom ID:";
cin>>t_id;
Node*ptr=head;
while(ptr!=NULL){
if(t_id==ptr->id){
cout<<"\n\nRoom ID:"<<ptr->id;
cout<<"\n\nCustomer Name:"<<ptr->name;
cout<<"\n\nRoom Allocated Date:"<<ptr->date;
cout<<"\n\nRoom Type:"<<ptr->roomtype;
}
ptr=ptr->next;
}
}
}
void Hotel::update(){
cout<<"\n\t---------------------HOTEL MANAGEMENT SYSTEM------------------\n"<<endl;
int  t_id;
if(head==NULL){
cout<<"\n\n Linked list is Empty";
}
else{
cout<<"\n\n Room ID";
cin>>t_id;
Node*ptr=head;
while(ptr!=NULL){
if(t_id==ptr->id){
cout<<"\nRoom ID";
cin>>ptr->id;
cout<<"\nCustomer Name";
cin>>ptr->name;
cout<<"\nAllocated Date";
cin>>ptr->date;
cout<<"\nRoom Type";
cin>>ptr->roomtype;
cout<<"\n\n\t\t Updated Record Sucessfully";
break;
}
ptr=ptr->next;
}
}
}
void Hotel::del(){
cout<<"\n\t---------------------HOTEL MANAGEMENT SYSTEM------------------\n";
int  t_id;
if(head==NULL){
cout<<"\n\n Linked list is Empty";
}
else{
cout<<"\n\n Room ID";
cin>>t_id;
}
if(t_id==head->id){
Node*ptr=head;
head=head->next;
delete ptr;
cout<<"Deleted Room Record Sucessfully\n";
}
else{
Node*pre=head;
Node*ptr=head;
while(ptr!=NULL){
if(t_id==ptr->id){
pre->next=ptr->next;
delete ptr;
cout<<"Deleted  Room Record Sucessfully";
break;
}
pre=ptr;
ptr=ptr->next;
}
if(ptr==NULL){
    cout<<"Room Not found."<<endl;
}
}
}
void Hotel::show(){
Node*ptr=head;
while(ptr!=NULL){
cout<<"\n\n Room ID:"<<ptr->id;
cout<<"\n\n Customer  Name:"<<ptr->name;
cout<<"\n\n Allocated Date:"<<ptr->date;
cout<<"\n\n Room Type:"<<ptr->roomtype;
ptr=ptr->next;
}
}
void Hotel::sort(){
if(head==NULL){
cout<<"\n\n Linked list is Empty";
menu();
}
int count=0,t_date,t_id;
string t_name,t_roomtype;
Node*ptr=head;
while(ptr!=NULL){
count++;
ptr=ptr->next;
}
for(int i=1;i<=count;i++){
Node*ptr=head;
for(int j=1;j<count;j++){
if(ptr->id>ptr->next->id){
t_id=ptr->id;
t_name=ptr->name;
t_date=ptr->date;
t_roomtype=ptr->roomtype;
//save data to current node
ptr->id=ptr->next->id;
ptr->name=ptr->next->name;
ptr->date=ptr->next->date;
ptr->roomtype=ptr->next->roomtype;
//save data into next node
ptr->next->id=t_id;
ptr->next->name=t_name;
 ptr->next->date=t_date;
 ptr->next->roomtype=t_roomtype;
}
ptr=ptr->next;
}
}
}
int main()
{
Hotel  h;
h.menu();
return 0;
}
