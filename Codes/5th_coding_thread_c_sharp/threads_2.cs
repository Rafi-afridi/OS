using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
 
namespace TestConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            ThreadStart testThreadStart = new ThreadStart(new Program().testThread);
            Thread testThread1 = new Thread(testThreadStart);
            
            ThreadStart testThreadStart1 = new ThreadStart(new Program().testThread);
            Thread testThread2 = new Thread(testThreadStart1);
 
            testThread1.Start();
            testThread2.Start();
            
            Console.ReadLine();
        }
 
        public void testThread()
        {
            //executing in thread
            int count = 0;
            while (count++ < 50)
            {
                Console.WriteLine("Thread Executed "+count+" times");
                Thread.Sleep(5);
            }
        }
    }
}