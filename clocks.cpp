// NOTE clock_gettime must link with -rt (real time library)
// g++ clocks.cpp -o clocks -lrt

#include <iostream>           // cout ...
using namespace std;

#include <cstdio>            // pipe
#include <inttypes.h>        // uint8_t ...
#include <time.h>            // clock_gettime
#include <sys/time.h>        // gettimeofday
#include <sys/utsname.h>     // uname

// typedef long long          int64_t;

/**
 * CPUID assembler instruction
 */
static inline void cpuid(unsigned int op, unsigned int *eax, unsigned int *ebx,
  unsigned int *ecx, unsigned int *edx)
{
  asm("cpuid" : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx) : "a" (op) : "cc");
}

/**
 * retrieve CPU Vender from CPU hardware
 */
char *CPUVendor(void)
{
   uint32_t eax, ebx, ecx, edx;
   static int Vendor[4];

   eax = 0; cpuid(eax, &eax, &ebx, &ecx, &edx);
   Vendor[0] = ebx; Vendor[1] = edx; Vendor[2] = ecx; Vendor[3] = 0;
   return (char *) Vendor;
}

/**
 * retrieve CPU Name from CPU hardware
 */
char *CPUName(void)
{
  uint32_t eax;
  static uint32_t Name[13];
  //                           &eax      &ebx      &ecx      &edx
  eax = 0x80000002; cpuid(eax, Name + 0, Name + 1, Name + 2, Name + 3);
  eax = 0x80000003; cpuid(eax, Name + 4, Name + 5, Name + 6, Name + 7);
  eax = 0x80000004; cpuid(eax, Name + 8, Name + 9, Name +10, Name +11);
  Name[12] = 0;

  return (char *) Name;
}


/**
 * print machine information
 */
void myMachineInfo()
{
  cout << "Vender=" << CPUVendor() << " Model=" << CPUName() << endl;

  char *cmd = (char*) "/usr/bin/lsb_release -d"; // -i ID, -d description, -r release, -c code name, or -a for all
  FILE *pipe = popen(cmd, "r");
  if(pipe) {
    char b[1000];
    while(fgets(b, sizeof(b)-1, pipe)) cout << b;
    pclose(pipe);
  }

  struct utsname uname_pointer;
  uname(&uname_pointer);
  cout << uname_pointer.sysname << " " 
       << uname_pointer.machine 
       << " kernel:" << uname_pointer.release
       << " (" << uname_pointer.version << ")"
       << endl;

  cout << "application (file " << __FILE__ << ") "
       <<  "compiled: " << __DATE__<< " "
       << __TIME__
       << endl;
}


class timers {
// other Linux timers rtc, hwclock, gethrtime
// for Windows, see Windows doc's on QueryPerformanceCounter() 
private:
    static const clockid_t clk_id = CLOCK_MONOTONIC;
    static const long BILLION = 1000000000L;
    static const long MILLION = 1000000L;
public:
    /**
     * time in processor clock cycles since power up, NOTE value wraps
     */
    uint64_t u64RDTSC() { 
       // RDTSC 'Read Time Stamp Counter' instruction - google it!
       unsigned a, d; 
       asm volatile("rdtsc" : "=a" (a), "=d" (d)); 
       return ((uint64_t)a) | (((uint64_t)d) << 32); 
    }
    /**
     * time in nsec since power up
     */
    uint64_t u64TimeNS() {
      // return gethrtime(); // real-time Linux function:- can't locate get_high_resolution_time function 
      struct timespec tp;
      clock_gettime(clk_id, &tp); // nanosec's since power up
      return BILLION * tp.tv_sec + tp.tv_nsec; // nsec
    }

    /**
     * return timer resolution
     */
    uint64_t getResNS() {
        struct timespec res;
        clock_getres(clk_id, &res);
        return BILLION * res.tv_sec + res.tv_nsec; // nsec
    }
    
    /**
     * time-of-day usec time
     */
    uint64_t u64TimeUS() {
      struct timeval tv;
      gettimeofday(&tv, 0);
      return MILLION * tv.tv_sec + tv.tv_usec; // nsec
    }
};

int main(int argc, char **argv) 
{
    myMachineInfo();


    timers t;
    cout << "time resolution = " << t.getResNS() << " nanosec." << endl; // nsec

    cout << "'sleep(n)' guarantees to sleep for at least 'n' seconds\n";
    uint64_t startRDTSC = t.u64RDTSC();
    uint64_t startNS = t.u64TimeNS();
    uint64_t startUS = t.u64TimeUS();
    sleep(1);
    uint64_t stopRDTSC = t.u64RDTSC();
    uint64_t stopNS = t.u64TimeNS();
    uint64_t stopUS = t.u64TimeUS();

    cout << "time for sleep(1) = " << stopRDTSC - startRDTSC << " TSC"  << endl;
    cout << "time for sleep(1) = " << stopNS    - startNS    << " nsec" << endl;
    cout << "time for sleep(1) = " << stopUS    - startUS    << " usec" << endl;
}

/* vim: set cin et ts=2 sw=2 cino=>1s,e0,n0,f0,{0,}0,^0,\:1s,=0,g1s,h0,t0,+1s,c3,(0,u0 : */
