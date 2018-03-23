#include <iostream>
#include <windows.h>
#include <winbase.h>
#include <vector>
#include <sstream>

using namespace std;
struct Date {
    int year;
    int month;
    int day;
};
string intNaString (int liczbaZamienianaNaString) {
    ostringstream ss;
    ss<<liczbaZamienianaNaString;
    string str=ss.str();
    return str;
}
void addDate(vector<Date>&dates) {
    Date date;
    int year;
    int month;
    int day;
    cout<<("Podaj rok: ");
    cin>>year;
    bool bissextile=false;
    if((year%4==0 && year%100!=0) || year%400==0) {
        cout<<"Rok "<<year<<" jest przestepny.";
        bissextile=true;
    } else {
        cout<<"Rok "<<year<<" nie jest przestepny.";
    }
    cout<<"Podaj miesiac: ";
    cin>>month;
    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout<<"Ten miesiac ma 31 dni.";
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        cout<<"Ten miesiac ma 30 dni.";
        break;

    case 2:
        if(bissextile) {
            cout<<"Ten miesiac ma 29 dni.";
        } else {
            cout<<"Ten miesiac ma 28 dni.";
        }
        break;
    default: {
        cout<<"To nie jest numer miesiaca.";
    }
    }
    cout<<endl<<"Podaj dzien: ";
    cin>>day;
    date.year=year;
    date.month=month;
    date.day=day;
    dates.push_back(date);
}
void displayAll(vector<Date>&dates) {
    int datesNumber=dates.size();
    for(int i=0; i<datesNumber; i++) {
        cout<<dates[i].year<<"-"<<dates[i].month<<"-"<<dates[i].day<<endl<<endl;
    }
}
string returnAsString(Date date) {
    string dateString = intNaString(date.year)+"-"+intNaString(date.month)+"-"+intNaString(date.day);
    return dateString;
}
void sortbuble(vector<Date>&dates) {
    int datesNumber=dates.size();
    for(int i=1; i<datesNumber; i++) {
        for(int j=datesNumber-1; j>=1; j--) {
            if(dates[j].year==dates[j-1].year) {
                if(dates[j].month==dates[j-1].month) {
                    if(dates[j].day<dates[j-1].day) {
                        Date temporaryDate;
                        temporaryDate = dates[j-1];
                        dates[j-1]=dates[j];
                        dates[j]=temporaryDate;
                    }
                }
                if(dates[j].month<dates[j-1].month) {
                    Date temporaryDate;
                    temporaryDate = dates[j-1];
                    dates[j-1]=dates[j];
                    dates[j]=temporaryDate;
                }
            }
            if(dates[j].year<dates[j-1].year) {
                Date temporaryDate;
                temporaryDate = dates[j-1];
                dates[j-1]=dates[j];
                dates[j]=temporaryDate;
            }

        }
    }
}
void checkIfDateOlder(vector<Date>&dates) {
    if(dates[0].year==dates[1].year) {
        if(dates[0].month==dates[1].month) {
            if(dates[1].day<dates[0].day) {
                cout<<"Druga data: "<<returnAsString(dates[1])<<" jest starsza"<<endl;
            }
        }
        if(dates[1].month<dates[0].month) {
            cout<<"Druga data: "<<returnAsString(dates[1])<<" jest starsza"<<endl;
        }
    }
    if(dates[1].year<dates[0].year) {
        cout<<"Druga data: "<<returnAsString(dates[1])<<" jest starsza"<<endl;
    }
}
int main() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    int yearThis = st.wYear;
    int monthThis = st.wMonth;
    int dayThis = st.wDay;
    cout << "Biezacy rok to " << yearThis<< endl;
    cout << "Biezacy miesiac to " << monthThis<< endl;
    cout << "Biezacy dzien  to " <<dayThis<< endl;
    Date date;
    date.year=yearThis;
    date.month=monthThis;
    date.day=dayThis;
    vector<Date> dates;
    dates.push_back(date);

    addDate(dates);
    addDate(dates);
    //checkWhichDateOlder(dates);
    //checkIfDateOlder(dates);
    //int datesNumber=dates.size();
    //cout<<endl<<datesNumber<<endl;
    displayAll(dates);
    sortbuble(dates);
    cout<<endl<<endl;
    displayAll(dates);

    return 0;
}
