// http://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm

// Polymorphism in C++

// The word polymorphism means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

// C++ polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

// Consider the following example where a base class has been derived by other two classes:

#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      int area()
      {
         cout << "Parent Shape class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0)
      {
        Shape(a, b); 
      }
      int area ()
      { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0)
      {
        Shape(a, b); 
      }
      int area ()
      { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};
// Main function for the program
// int main( )
// {
   // Shape *shape;
   // Rectangle rec(10,7);
   // Triangle  tri(10,5);
// 
   // // store the address of Rectangle
   // shape = &rec;
   // // call rectangle area.
   // shape->area();
// 
   // // store the address of Triangle
   // shape = &tri;
   // // call triangle area.
   // shape->area();
  //  
   // return 0;
// }

// When the above code is compiled and executed, it produces the following result:

// Parent class area
// Parent class area

// The reason for the incorrect output is that the call of the function area() is being set once by the compiler as the version defined in the base class. This is called static resolution of the function call, or static linkage - the function call is fixed before the program is executed. This is also sometimes called early binding because the area() function is set during the compilation of the program.

// But now, let's make a slight modification in our program and precede the declaration of area() in the Shape class with the keyword virtual so that it looks like this:

class ShapeV {
   protected:
      int width, height;
   public:
      ShapeV( int a=0, int b=0)
      {
         cout << "Parent ShapeV constructor a=" << a << ", b=" << b << endl;
         width = a;
         height = b;
      }
      virtual int area()
      {
         cout << "Parent ShapeV class area : (always returns 0)" <<endl;
         return 0;
      }
};
class RectangleV: public ShapeV{
   public:
      RectangleV( int a=0, int b=0)
      {
        cout << "RectangleV constructor a=" << a << ", b=" << b << endl;
        ShapeV(a, b); 
      }
      int area ()
      { 
         int areaCalc = width * height;
         cout << "RectangleV class area :" <<endl;
         return areaCalc;
      }
};
class TriangleV: public ShapeV{
   public:
      TriangleV( int a=0, int b=0)
      {
        cout << "TriangleV constructor a=" << a << ", b=" << b << endl;
        ShapeV(a, b); 
      }
      int area ()
      { 
         int areaCalc = width * height / 2;
         cout << "TriangleV class area :" <<endl;
         return areaCalc;
      }
};

// After this slight modification, when the previous example code is compiled and executed, it produces the following result:

// Rectangle class area
// Triangle class area

// This time, the compiler looks at the contents of the pointer instead of it's type. Hence, since addresses of objects of tri and rec classes are stored in *shape the respective area() function is called.

// As you can see, each of the child classes has a separate implementation for the function area(). This is how polymorphism is generally used. You have different classes with a function of the same name, and even the same parameters, but with different implementations.
// Virtual Function:

// A virtual function is a function in a base class that is declared using the keyword virtual. Defining in a base class a virtual function, with another version in a derived class, signals to the compiler that we don't want static linkage for this function.

// What we do want is the selection of the function to be called at any given point in the program to be based on the kind of object for which it is called. This sort of operation is referred to as dynamic linkage, or late binding.
// Pure Virtual Functions:

// It's possible that you'd want to include a virtual function in a base class so that it may be redefined in a derived class to suit the objects of that class, but that there is no meaningful definition you could give for the function in the base class.

// We can change the virtual function area() in the base class to the following:

class ShapePV {
   protected:
      int width, height;
   public:
      // ShapePV( ) {}  // can never be called because class contains a pure virtual function
      // pure virtual function
      virtual int area() = 0;
};
class RectanglePV: public ShapePV{
   public:
      RectanglePV( int a=0, int b=0)
      {
        // ShapePV(a, b); 
        width = a;
        height = b;
      }
      int area ()
      { 
         int areaCalc = width * height;
         cout << "RectanglePV class area :" <<endl;
         return areaCalc;
      }
};
class TrianglePV: public ShapePV{
   public:
      TrianglePV( int a=0, int b=0)
      {
        // ShapePV(a, b); 
        width = a;
        height = b;
      }
      int area ()
      { 
         int areaCalc = width * height / 2;
         cout << "TrianglePV class area :" <<endl;
         return areaCalc;
      }
};

// The = 0 tells the compiler that the function has no body and above virtual function will be called pure virtual function.
// Main function for the program
int main( )
{
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;
   // call rectangle area.
   std::cout << shape->area() << endl;

   // store the address of Triangle
   shape = &tri;
   // call triangle area.
   std::cout << shape->area() << endl;
   
// virtual, V
   ShapeV *shapeV;
   RectangleV recV(10,7);
   TriangleV triV(10,5);

   // store the address of Rectangle
   shapeV = &recV;
   // call rectangle area.
   std::cout << shapeV->area() << endl;

   // store the address of Triangle
   shapeV = &triV;
   // call triangle area.
   std::cout << shapeV->area() << endl;
   
// pure virtual, PV
   ShapePV *shapePV;
   RectanglePV recPV(10,7);
   TrianglePV  triPV(10,5);

   // store the address of Rectangle
   shapePV = &recPV;
   // call rectangle area.
   std::cout << shapePV->area() << endl;

   // store the address of Triangle
   shapePV = &triPV;
   // call triangle area.
   std::cout << shapePV->area() << endl;
   
   return 0;
}
