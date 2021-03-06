# ifndef SPL_POINT_HH
# define SPL_POINT_HH

#include "any.hh"
#include "Domain.hh"

  namespace spl{
    /* **
     * Point structure is a convenient way to access a Signal
     */
    template<typename E, unsigned dim>
    struct Point : public global::Any<E>
    {
      const unsigned &operator[](unsigned i) const;
      unsigned &operator[](unsigned i);


      E operator+(const E &p) const;
      E& operator+=(const E &p);
      E operator-(const E &p) const;
      E& operator-=(const E &p);

      Point();
      Point(const Point<E,dim>& p);
      void operator=(const E &p);
      bool operator==(const E &p) const;

      protected:
      unsigned _coords[dim];
    };  

    struct Point1D : public Point<Point1D,1>{
      unsigned &_x;
      typedef Point<Point1D,1> parent;

      Point1D(unsigned x) 
      : _x(_coords[0])
      {
        _x = x;
      }
      Point1D() 
      : _x(_coords[0])
      {
        _x = 0;
      }
      void operator=(const Point1D &p) 
      {
        parent::operator=(p);
      }

      Point1D(const Point1D &p)
      : parent(p)
      , _x(_coords[0])
      {}

    };
    struct Point2D : public Point<Point2D,2>{
      unsigned &_x, &_y;
      typedef Point<Point2D,2> parent;
      Point2D(unsigned x, unsigned y) 
      : _x(_coords[0])
      , _y(_coords[1])
      {
        _x = x;
        _y = y;
      }
      Point2D() 
      : _x(_coords[0])
      , _y(_coords[1])
      {
        _x = 0;
        _y = 0;
      }      
      void operator=(const Point2D &p) 
      {
        parent::operator=(p);
      }

      Point2D(const Point2D &p)
      : parent(p)
      , _x(_coords[0])
      , _y(_coords[1])
      {}
    };
    struct Point3D : public Point<Point3D,3>{
      typedef Point<Point3D,3> parent;
      unsigned &_x, &_y, &_z;
      Point3D(unsigned x, unsigned y, unsigned z) 
      : _x(_coords[0])
      , _y(_coords[1])
      , _z(_coords[2])
      {
        _x = x;
        _y = y;
        _z = z;
      }
      Point3D() 
      : _x(_coords[0])
      , _y(_coords[1])
      , _z(_coords[2])
      {
        _x = 0;
        _y = 0;
        _z = 0;
      }

      Point3D(const Point3D &p)
      : parent(p)
      , _x(_coords[0])
      , _y(_coords[1])
      , _z(_coords[2])
      {}

      void operator=(const Point3D &p) 
      {
        parent::operator=(p);
      }
    };
  }//!spl 

# include "Point.hxx"

# endif
