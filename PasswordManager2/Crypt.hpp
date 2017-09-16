#ifndef CRYPT_H
#define CRYPT_H

#include <sys/types.h>
#include <dirent.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "aes.h"
#include "sha.h"
#include "pwdbased.h"
#include "eax.h"
#include "hex.h"

using namespace CryptoPP;

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;


class Crypt{

public:

   Crypt(string&,string&);

   //procurar o arquivo
   bool isUserValid();
   //ler o arquivo
   string getData(string&) const;
   //gravar o arquivo
   void setData(string&,string&);

   //deletar usuário se a senha for correta
   void deleteUser(string&);

   //criar um novo arquivo
   void static createData(string& ,string& ,string&);



private:
   string fileName;
   bool isValid;
   const int keySize = AES::DEFAULT_KEYLENGTH;
   const int iterations = 100;

   void getDir(vector<string>&);

   // validar a senha do usuario 
   bool validateUser(string&, string&);

   // ler arquivo encriptado
   string readEncrypted(string&);

   // gerar key derivada da senha do usuario
   SecByteBlock generateKey(string&);

   // retorna o texto decryptado, porém gera uma excecao em senha errada
   string decryptate(SecByteBlock, string);
};

#endif