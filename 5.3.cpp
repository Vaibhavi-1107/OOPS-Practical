/*A team of software developers was tasked with creating a graphical simulation where operations on
2D points play a crucial role. To facilitate this, they designed a class Point that encapsulates the
coordinates 𝑥 and 𝑦. The class provides flexibility through overloaded operators to manipulate points
efficiently. The unary operator - is overloaded to negate the coordinates of a point, while the binary
operator + enables the addition of two points. Additionally, the equality operator == is overloaded to
compare whether two points have identical coordinates.
The development process required performing various operations between multiple points. To
manage these operations effectively, a mechanism was needed to track and potentially undo them.
This challenge prompted two approaches: using a ready-made dynamic stack structure or building a
custom stack implementation. By managing a sequence of operations in reverse, the stack-based
design allowed for a systematic undo capability, crucial for simulations involving iterative adjustments.*/
/*#include<iostream>
using namespace std;
class Point
{
    private:
        int point1;
        int point2;
    public:
        Point(int x=0,int y=0):point1(x),point2(y){}

        Point operator +(const Point& obj) const{
            return Point(point1+obj.point1,point2+obj.point2);
        }
        void display() const {
                cout<<"("<<point1 <<","<<point2<<")"<<endl;
        }
 /*   public:
        //constructor to initialize the coordinates
        Point(int x=0,int y=0){
            point1=x;
            point2=y;
        }
        //Overloading + operator
        Point operator +(const Point& obj)
        {
            Point result;
            result.point1=this->point1+obj.point1;
            result.point2=this->point2+obj.point2;
            return result;
        }
        //Function to display the coordinates
        void display() const
        {
           cout<<"Result:"<<result<<endl;
        }
};
int main()
{
    Point obj1,obj2,obj3;
    obj1(2,3);
    obj2(4,3);
    obj3=obj1+obj2;
    obj3.display();
 //   obj2.display();
    return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;

// Point class encapsulating x and y
class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload unary - operator to negate coordinates
    Point operator-() const {
        return Point(-x, -y);
    }

    // Overload binary + operator to add two points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload == operator to compare two points
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

// Custom stack to store Point operations
class PointStack {
private:
    vector<Point> stack;

public:
    void push(const Point& p) {
        stack.push_back(p);
    }

    bool isEmpty() const {
        return stack.empty();
    }

    Point pop() {
        if (!isEmpty()) {
            Point top = stack.back();
            stack.pop_back();
            return top;
        } else {
            cerr << "Stack is empty!" << endl;
            return Point();
        }
    }

    void showStack() const {
        cout << "Current Stack: ";
        for (const auto& p : stack) {
            p.display();
            cout << " ";
        }
        cout << endl;
    }
};

int main() {
    Point p1(2, 3), p2(4, -1);

    // Display original points
    cout << "Point 1: "; p1.display(); cout << endl;
    cout << "Point 2: "; p2.display(); cout << endl;

    // Use overloaded + operator
    Point sum = p1 + p2;
    cout << "Sum: "; sum.display(); cout << endl;

    // Use unary - operator
    Point neg = -p1;
    cout << "Negation of Point 1: "; neg.display(); cout << endl;

    // Use equality operator
    cout << "Are p1 and p2 equal? " << (p1 == p2 ? "Yes" : "No") << endl;

    // Using the stack for undo functionality
    PointStack opStack;
    opStack.push(p1);
    opStack.push(p2);
    opStack.push(sum);

    opStack.showStack();

    // Undo last operation
    cout << "Undo last operation...\n";
    Point last = opStack.pop();
    cout << "Popped: "; last.display(); cout << endl;

    opStack.showStack();
    cout<<"Vaibhavi 24CE053";
    return 0;
}

