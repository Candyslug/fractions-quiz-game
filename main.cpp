#include <time.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int total_fractions = 2;
int numerator_min = 1;
int numerator_max = 10;
int denominator_min = 1;
int denominator_max = 10;

int rand_int(int min=1, int max=10) {
  return min + (rand() % (max - 1));
}

struct fraction {
  fraction() {
    numerator=rand_int();
    denominator=rand_int();
  }
  fraction(int n, int d) {
    numerator = n;
    denominator = d;
  } 
  int numerator;
  int denominator;
  double answer() {
    return double(numerator) / double(denominator);
  }
  void reveal() {
    cout<<"(";
    cout<<numerator; cout<<"/"; cout<<denominator;
    cout<<")";
  }
};

struct fractions {
  fractions(int amount=total_fractions) {
    for (int i = 0; i < amount; i++) {
      list.push_back(fraction());
    }
  }
  void reveal() {
    for (int i = 0; i < list.size(); i++) {
      list[i].reveal();
    }
  }
  void reveal_op(int i, bool show_answer = false) {
    if (i==0)
      cout<<" + ";
    else if (i==1)
      cout<<" - ";
    else if (i==2) 
      cout<<" x ";
    else if (i==3) 
      cout<<" / ";
  }
  vector<fraction> list;
  void compute() {
    double a = 0;
    int op;
    for (int i = 0; i < list.size(); i++) {
      if (a != 0) {
        op = rand_int(0, 4); 
        switch (op) {
          case 0:
            a += list[i].answer(); 
            reveal_op(op);
            list[i].reveal();
            break;
          case 1:
            a -= list[i].answer();
            reveal_op(op);
            list[i].reveal();
            break;
          case 2:
            a *= list[i].answer();
            reveal_op(op);
            list[i].reveal();
            break;
          case 3:
            a /= list[i].answer();
            reveal_op(op);
            list[i].reveal();
            break;
        }
      }
      else {
        list[i].reveal();
        a = list[i].answer();
      }
    }
    answer = a;
    cout<< " = ? ";
    cout<<endl;
  }
  double answer;
  void guess_answer() {
    double g1;
    double g2;
    cout<<endl;
    cout<< "Numerator:   ";
    cin >> g1;
    cout<<"            ----"<<endl;
    cout<<"Denominator: ";
    cin >> g2;
    cout<<endl;
    double g = g1/g2;
    if (g == answer)
      cout<<"Correct";
    else
      cout<<"Incorrect";
    cout<<", the answer is: ";
    cout<<answer<<endl;
  }
};

int main() {   
  srand(time(NULL));
  fractions f;
  f.compute();
  f.guess_answer();
  return 0;
}
