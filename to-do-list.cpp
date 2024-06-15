#include<bits/stdc++.h>
#include<string>
#include<fstream>
using namespace std;

struct todolist
{
    int id;
    string task;
};
int ID = 0;

void banner();
void addtask();
void viewtask();
int searchtask();
void deletetask();



void banner(){
    // You can put some banner code here if needed
}

void addtask(){
    system("cls");
    banner();
    todolist todo;
    cout<<"Enter new task:"<<endl;
    cin.get();
    getline(cin,todo.task);
    char save;
    cout<<"Save? (y/n): ";
    cin>>save;
    if(save == 'y'){
        ID++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout<<ID<<"\n"<<todo.task<<"\n";
        fout.close();
        
        char more;
        cout<<"Add more task? (y/n): ";
        cin>>more;
        
        if(more == 'y'){
            addtask();
        }
        else{
            system("cls");
            cout<<"Added successfully"<<endl;
            return;
        }
    }
    system("cls");
}

void viewtask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout<<"Tasks:"<<endl;
    
    while(!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.task != ""){
            cout<<"\t"<<todo.id<<": "<<todo.task<<endl;
        }
    }
    fin.close();
    char exit;
    cout<<"Exit?(y/n): ";
    cin>>exit;
    if(exit != 'y')
    {
        viewtask();
    }
    system("cls");
}

int searchtask(){
    system("cls");
    banner();
    int id;
    cout<<"Enter task ID: ";
    cin>>id;
    todolist todo;
    ifstream fin("todo.txt");
    while(!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id == id){
            system("cls");
            cout<<"\t"<<todo.id<<": "<<todo.task<<endl;
            return id;
        }
    }
    system("cls");
    cout<<"Not found"<<endl;
    return 0;
}

void deletetask(){
    system("cls");
    int id = searchtask();
    if(id != 0){
        char del;
        cout<<"\n\tDelete? (y/n): ";
        cin>>del;
        if(del == 'y')
        {
            todolist todo;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream fin;
            fin.open("todo.txt");
            int index = 1;
            while(!fin.eof()){
                fin>>todo.id;
                fin.ignore();
                getline(fin,todo.task);
                if(todo.id != id){
                    tempfile<<index<<"\n"<<todo.task<<"\n";
                    index++;
                }
            }
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout<<"\n\tDeleted successfully!"<<endl;
        }
        else{
            system("cls");
            cout<<"Not deleted"<<endl;
        }
    }
}
int main(){
    cout<<"\t\t\t**"<<endl;
    cout<<"  \t\t\t\t\t   TO-DO-LIST"<<endl;
    cout<<"\t\t\t**"<<endl;
    
    system("cls");
    while(true)
    {
        banner();
        cout<<" \n\t1. Add Task";
        cout<<"\n\t2. view Task";
        cout<<"\n\t3. Search Task";
        cout<<"\n\t4. Delete Task" <<endl;
        
        int choice;
        
        cout<<"\n\t Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                  addtask();
                  break;
            case 2:
                  viewtask();
                  break;
            case 3:
                  searchtask();
                  break;
            case 4:
                  deletetask();
                  break;
            default:
                  cout << "Invalid choice. Please try again." << endl;
                  break;
        }
    }
    return 0;
}