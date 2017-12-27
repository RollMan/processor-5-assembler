#define LDA   0x1002
#define ANA   0x1005
#define ORA   0x1006
#define XRA   0x1007
#define ADA   0x1008
#define SUA   0x1009
#define MUA   0x100a
#define SRA   0x100b
#define SLA   0x100c
#define SRL   0x100d
#define SLL   0x100e
#define JMP   0x2002
#define JZ    0x2102
#define CALL  0x2012
#define STA   0x3000
#define RET   0x4000
#define LDAI  0x9002
#define ANAI  0x9005
#define ORAI  0x9006
#define XRAI  0x9007
#define ADAI  0x9008
#define SUAI  0x9009
#define MUAI  0x900a
#define SRAI  0x900b
#define SLAI  0x900c
#define SRLI  0x900d
#define SLLI  0x900e
#define JMPI  0xa002
#define JZI   0xa102
#define CALLI 0xa012
#define STAI  0xb000

#include <vector>
#include <map>
#include <string>
#include <utility>

class OP{
  public:
    std::map<std::string, int> v;
    OP(){
      v.insert( std::pair<std::string, int> ("LDA"   , LDA)  );
      v.insert( std::pair<std::string, int> ("ANA"   , ANA)  );
      v.insert( std::pair<std::string, int> ("ORA"   , ORA)  );
      v.insert( std::pair<std::string, int> ("XRA"   , XRA)  );
      v.insert( std::pair<std::string, int> ("ADA"   , ADA)  );
      v.insert( std::pair<std::string, int> ("SUA"   , SUA)  );
      v.insert( std::pair<std::string, int> ("MUA"   , MUA)  );
      v.insert( std::pair<std::string, int> ("SRA"   , SRA)  );
      v.insert( std::pair<std::string, int> ("SLA"   , SLA)  );
      v.insert( std::pair<std::string, int> ("SRL"   , SRL)  );
      v.insert( std::pair<std::string, int> ("SLL"   , SLL)  );
      v.insert( std::pair<std::string, int> ("JMP"   , JMP)  );
      v.insert( std::pair<std::string, int> ("JZ"    , JZ )  );
      v.insert( std::pair<std::string, int> ("CALL"  , CALL) );
      v.insert( std::pair<std::string, int> ("STA"   , STA)  );
      v.insert( std::pair<std::string, int> ("RET"   , RET)  );
      v.insert( std::pair<std::string, int> ("LDAI"  , LDAI) );
      v.insert( std::pair<std::string, int> ("ANAI"  , ANAI) );
      v.insert( std::pair<std::string, int> ("ORAI"  , ORAI) );
      v.insert( std::pair<std::string, int> ("XRAI"  , XRAI) );
      v.insert( std::pair<std::string, int> ("ADAI"  , ADAI) );
      v.insert( std::pair<std::string, int> ("SUAI"  , SUAI) );
      v.insert( std::pair<std::string, int> ("MUAI"  , MUAI) );
      v.insert( std::pair<std::string, int> ("SRAI"  , SRAI) );
      v.insert( std::pair<std::string, int> ("SLAI"  , SLAI) );
      v.insert( std::pair<std::string, int> ("SRLI"  , SRLI) );
      v.insert( std::pair<std::string, int> ("SLLI"  , SLLI) );
      v.insert( std::pair<std::string, int> ("JMPI"  , JMPI) );
      v.insert( std::pair<std::string, int> ("JZI"   , JZI)  );
      v.insert( std::pair<std::string, int> ("CALLI" , CALLI));
      v.insert( std::pair<std::string, int> ("STAI"  , STAI) );
    }
};
