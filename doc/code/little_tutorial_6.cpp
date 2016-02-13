/** little_tutorial_6.cpp
 *
 * (C) Copyright 2011 François Mauger, Christian Pfligersdorffer
 *
 * Use, modification and distribution is subject to the Boost Software
 * License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 */

/**
 * The intent of this program is to serve as a tutorial for
 * users of the little archive in the framework of
 * the Boost/Serialization library.
 *
 * This sample program shows how to use a little archive
 * associated to a memory buffer to copy a non-copyable object.
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <boost/utility.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/device/array.hpp>

#include <boost/cstdint.hpp>
#include <boost/archive/little_oarchive.hpp>
#include <boost/archive/little_iarchive.hpp>

using namespace std;

/* A foo noncopyable class */
struct foo : boost::noncopyable
{
  uint32_t status;
  double   value;
  double   special;

  string to_string () const
  {
    ostringstream sout;
    sout << "foo={status=" << status << "; value=" << value  << "; special=" << special<< "}";
    return sout.str();
  }

  template<class Archive>
  void serialize (Archive & ar, const unsigned int version)
  {
    ar & status;
    ar & value;
    ar & special;
    return;
  }

};

// A templatized copy function for Boost/Serialization equipped classes.
// Here we use little archives associated to a memory buffer :
template <class Serializable>
void copy (const Serializable & source, Serializable & target)
{
  namespace io = boost::iostreams;
  namespace ba = boost::archive;
  if (&source == &target) return; // self-copy guard
  typedef std::vector<char> buffer_type;
  buffer_type buffer;
  buffer.reserve (1024);
  {
    io::stream<io::back_insert_device<buffer_type> > output_stream (buffer);
    ba::little_oarchive olittle (output_stream);
    olittle & source;
  }
  {
    io::stream<io::array_source> input_stream (&buffer[0], buffer.size ());
    ba::little_iarchive ilittle (input_stream);
    ilittle & target;
  }
  return;
}

int main (void)
{
  // Some instance of the 'foo' class :
  foo dummy;
  dummy.status = 1;
  dummy.value = 3.14159;
  dummy.special = numeric_limits<double>::quiet_NaN ();
  clog << "dummy is : " << dummy.to_string () << endl;

  // Another instance of the 'foo' class :
  foo clone;

  /* The following instruction is forbidden because foo 
     inherits 'boost::noncopyable' :
   
   clone = dummy; // this ends in a compilation error.
   
   */

  // Anyway, we can use this workaround :
  copy (dummy, clone);
  clog << "clone is : " << clone.to_string () << endl;

  return 0;
}

// end of little_tutorial_6.cpp
