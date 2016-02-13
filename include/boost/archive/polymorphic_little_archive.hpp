/*****************************************************************************/
/**
 * \file polymorphic_little_archive.hpp
 * \brief Needed for unit tests on little archives.
 * \author christian.pfligersdorffer@gmx.at
 *
 * Header for testing little archives with all of the serialization tests.
 * Before use copy all hpp files from this directory to your boost folder
 * boost_.../libs/serialization/test and run from there a visual studio
 * prompt with b2 oder bjam -sBOOST_ARCHIVE_LIST=little_archive.hpp
 *
 * \note Since little archives version 5.0 we depend on program_options!
 * Edit libs/serialization/test/Jamfile.v2 and change the requirements to
 * : requirements <source>/boost/filesystem <source>/boost/program_options
 */
/****************************************************************************/

#pragma warning( disable:4217 4127 4310 4244 4800 4267 )

// text_archive test header
// include output archive header
#include "little_oarchive.hpp"
// set name of test output archive
typedef boost::archive::polymorphic_little_oarchive test_oarchive;
// set name of test output stream
typedef std::ofstream test_ostream;

// repeat the above for input archive
#include "little_iarchive.hpp"
typedef boost::archive::polymorphic_little_iarchive test_iarchive;
typedef std::ifstream test_istream;

// define open mode for streams
// binary archives should use std::ios_base::binary
#define TEST_STREAM_FLAGS std::ios_base::binary
