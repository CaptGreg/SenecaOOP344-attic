// http://www.tutorialspoint.com/cplusplus/cpp_quick_guide.htm

#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      float width, height;
   public:
      Shape( float a=0, float b=0)
      {
         width  = a;
         height = b;
      }
      void Print()
      {
         cout << "width=" << width << " height=" << height << endl;
      }
      float area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape{
   public:
      Rectangle( float a=0, float b=0)
      {
        Shape(a, b); 
        Print();
      }
      float area ()
      { 
         Print();
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( float a=0, float b=0)
      {
        Shape(a, b); 
        Print();
      }
      float area ()
      { 
         Print();
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};

// Main function for the program
int main(int argc, char **argv )
{
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);
 
   // store the address of Rectangle
   shape = &rec;
   // call rectangle area.
   cout << shape->area() << "\n";
   cout << rec.area() << "\n";
   // cout << rec.Print() << "\n";
 
   // store the address of Triangle
   shape = &tri;

   // call triangle area.
   cout << shape->area() << "\n";
   cout << tri.area() << "\n";
   // cout << tri.Print() << "\n";
   
   return 0;
}
