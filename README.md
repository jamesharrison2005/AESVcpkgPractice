Using the Crypto++ library with vcpkg. Just uses sample code from https://www.cryptopp.com/wiki/Advanced_Encryption_Standard that I've separated into a class

How to run: should just be able to clone the repo and run the vcpkg integrate install command if you don't already have it installed
How to Run:
1. In powershell run the following command(if you dont have vcpkg installed already): vcpkg integrate install<br />
2. go to Project Properties -> vcpkg -> Use Vcpkg Manifest -> Yes<br />
3. Build the solution which downloads the Crypto++ library and links it to your project<br />
4. If the build fails, you may need to install vcpkg.exe manually (also check vcpkg.json has the dependency cryptopp)<br />
5. Run the Program<br />
6. If that doesn't work I'm sorry, I don't know how to use vcpkg properly<br />
