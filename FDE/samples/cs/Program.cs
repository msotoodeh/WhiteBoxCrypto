using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using kplus.fde.abc;

namespace TestCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string pt = "1234-5678-9012-3456";
            if (args.Length > 0) pt = args[0];

            Console.WriteLine("Key name ......... {0}", kplus.fde.abc.RawKey.keyName);
            Console.WriteLine("Key id ........... 0x{0:x8}", kplus.fde.abc.Format.keyId());
            Console.WriteLine("Key attributes ... 0x{0:x8}", kplus.fde.abc.Format.keyAttr());

            string ct = kplus.fde.abc.encrypt.transform(pt);
            string tt = kplus.fde.abc.decrypt.transform(ct);

            Console.WriteLine("Encrypt/Decrypt:");
			Console.WriteLine("{0} --E--> {1} --D--> {2} : {3}", 
			                  pt, ct, tt, tt.Equals(pt) ? "PASS" : "FAIL");

            // Switch E and D
            ct = kplus.fde.abc.decrypt.transform(pt);
            tt = kplus.fde.abc.encrypt.transform(ct);

            Console.WriteLine("Decrypt/Encrypt:");
			Console.WriteLine("{0} --D--> {1} --E--> {2} : {3}", 
			                  pt, ct, tt, tt.Equals(pt) ? "PASS" : "FAIL");
        }
    }
}
