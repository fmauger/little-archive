# little-archive
#### C++ portable archive for boost::serialization

Formerly called *eos portable archive* this extension to boost serialization contains a little-endian portable binary archive, which has been around and in use since 2007. Several projects, both industry and academia have been relying on the advantages in both data footprint and runtime efficiency over text and xml archives. For documentation and some coding examples see https://rawgit.com/pfligersdorffer/little-archive/develop/doc/little-tutorial.html or doc/little-tutorial.html.

Originally evolving from Robert Ramey's portable binary archive example the little archive adds cross-platform IEEE floating point support by leveraging Johan Rade's work on fp_utilities. Generic integer type serialization relies on Beman Dawes' endian library which is officially listed since version 1.58.

This repository provides a place to prepare the little archive for integration into the official boost serialization library. For that purpose the archive code will change but *by all means* maintain backwards compatibility to all of your existing data that is out there. Furthermore it is no longer necessary that the archive code compiles and integrates with other boost versions than the current one. If you are stuck with a legacy compiler and/or older boost version then you can have a look at http://epa.codeplex.com, support goes back to 1.33.1.

#### Some testimonials from users:

"We've been happily using this library in our product for a few years. While every library dependency is inconvenient, we found that in practice, the updates were either mostly timely, or there were no incompatibilities (with the latest boost libraries I mean) at all." (2014)

"The archives are really critical for us, and I love them. We have been using them for years and years and we store >~10 TB of raw data for experimental particle physics (some hard work we cannot risk to loose). It will be even more from next year (expected ~100TB)! Thanks a lot again for this great work (60 kB of code that do change life!)" (2015)

Kind regards,
Christian Pfligersdorffer
