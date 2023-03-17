#include <iostream>
using namespace std;

struct node{
    string sepatu;
    int tahun;
    node* next;
};

class linked{
    private:
        node *head, *tail,*cur;
    public:
        linked(){
            head=NULL;
            tail=NULL;
        }

        void addFront(string sepatu,int tahun){
            node *tmp = new node;
            tmp->sepatu = sepatu;
            tmp->tahun = tahun;
            tmp->next = NULL;

            if(head==NULL){
                head = tmp;
                tail = tmp;
            }else{
                tmp->next = head;
                head = tmp;
            }
        }

        void addBack(string sepatu,int tahun){
            node *tmp = new node;
            tmp->sepatu = sepatu;
            tmp->tahun = tahun;
            tmp->next = NULL;
            
            if(head==NULL){
                head = tmp;
                tail = tmp;
            }else{
                tail->next = tmp;
                tail = tail->next;
            }
        }

        void addMiddle(string sepatu,int tahun,int posisi){
            node *tmp = new node;
            tmp->sepatu = sepatu;
            tmp->tahun = tahun;
            tmp->next = NULL;

            cur = head;

            if(head==NULL){
                head = tmp;
                tail = tmp;
            }else{
                for (int i = 1; i < posisi-1; i++){
                    cur = cur->next;
                }
                tmp->next = cur->next;
                cur->next = tmp;
            }
        }
        
        void menuAdd(){
            int t = 0,tahun,posisi=0;
            string sepatu;
            cout<<"posisi darimana : "<<endl;
            cout<<"1. depan"<<endl;
            cout<<"2. belakang"<<endl;
            cout<<"3. tengah/sisipkan"<<endl;
            cout<<"> ";
            cin>>t;

            if(t == 1){
                cout<<"masukkan merk sepatu : ";
                cin>>sepatu;
                cout<<"masukkan tahun pembuatan : ";
                cin>>tahun;

                addFront(sepatu,tahun);
            }else if(t == 2){
                cout<<"masukkan merk sepatu : ";
                cin>>sepatu;
                cout<<"masukkan tahun pembuatan : ";
                cin>>tahun;

                addBack(sepatu,tahun);
            }else if(t == 3){
                cout<<"masukkan merk sepatu : ";
                cin>>sepatu;
                cout<<"masukkan tahun pembuatan : ";
                cin>>tahun;
                cout<<"posisi ke- : ";
                cin>>posisi;

                addMiddle(sepatu,tahun,posisi);
            }
                    
        }

        void rmvFront(){
            cur = head;
            head = cur->next;
            delete cur;
        }

        void rmvBack(){
            node *hps = tail;
            cur = head;
            while(cur->next!=tail){
                cur = cur->next;
            }
            tail = cur;
            cur->next=NULL;
            delete hps;
        }


        void rmvMiddle(int posisi){
            node *before;
            node *rmv;
            cur = head;
            for (int i = 1; i <= posisi; i++){
                if(i == posisi-1){
                  before = cur;
                }
                if(i == posisi){
                    rmv = cur;
                }
                cur = cur->next;
            }
            before->next = cur;
            delete rmv;
        } 

        void menuRmv(){
            int t = 0,posisi = 0; 
            cout<<"posisi darimana : "<<endl;
            cout<<"1. depan"<<endl;
            cout<<"2. belakang"<<endl;
            cout<<"3. tengah/sisipkan"<<endl;
            cout<<"> ";
            cin>>t;
            cout<<"\n";
            switch (t){
            case 1:
                rmvFront();
                break;
            
            case 2:
                rmvBack();
                break;

            case 3:
                cout<<"posisi ke- : ";
                cin>>posisi;
                rmvMiddle(posisi);
                break;
            }
        }

        void display(){
            cout<<endl;
            cur = head;
            while(cur!=NULL){
                cout<<cur->sepatu<<endl;
                cout<<cur->tahun<<endl;
                cur = cur->next;
            cout<<endl;
            }
        }

        void menu(){
            int choice = 0;
            input_menu : 
            cout<<"Data Sepatu"<<endl;
            cout<<"Masukkan menu : "<<endl;
            cout<<"1. menambahkan data"<<endl;
            cout<<"2. menghapus data"<<endl;
            cout<<"3. tampilkan data"<<endl;
            cout<<"4. exit"<<endl;
            cout<<"> ";
            cin>>choice;
            do
            {
                switch (choice)
                {
                case 1:
                    menuAdd();
                    cout<<"\n";
                    goto input_menu;
                    break;
                case 2:
                    menuRmv();
                    cout<<"\n";
                    goto input_menu;
                    break;
                case 3:
                    display();
                    cout<<"\n";
                    goto input_menu;
                    break;
               
                }
            } while (choice!=4);
        }
};




int main(){
    linked myLinked;
    myLinked.menu();
    return 0;
}