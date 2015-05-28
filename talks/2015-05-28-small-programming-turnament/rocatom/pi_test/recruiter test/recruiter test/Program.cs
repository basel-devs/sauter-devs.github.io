using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace recruiter_test
{
    class Program
    {
        static void Main(string[] args)
        {
            string value = CalculatePi(19);//Math.Round(Math.PI, 15).ToString();
    string fileName = "D:\\pi_test";
    int index = 0;
    using (System.IO.StreamReader reader = new System.IO.StreamReader(fileName))
    {
        if (String.IsNullOrEmpty(value))
            Console.WriteLine("0");
        StringSearch valueSearch = new StringSearch(value);
        int readChar;
        while ((readChar = reader.Read()) >= 0)
        {
            ++index;
            if (valueSearch.Found(readChar))
                Console.WriteLine("pi was found at index {0}", index - value.Length);
        }
    }
    Console.WriteLine("am I hired ?");
}

        static public string CalculatePi(int digits)
        {

            //Stanley Rabinowitz and Stan Wagon - Spigot Algorithm
            string result = "";
            digits++;

            uint[] x = new uint[digits * 3 + 2];
            uint[] r = new uint[digits * 3 + 2];

            for (int j = 0; j < x.Length; j++)
                x[j] = 20;

            for (int i = 0; i < digits; i++)
            {
                uint carry = 0;
                for (int j = 0; j < x.Length; j++)
                {
                    uint num = (uint)(x.Length - j - 1);
                    uint dem = num * 2 + 1;

                    x[j] += carry;

                    uint q = x[j] / dem;
                    r[j] = x[j] % dem;

                    carry = q * num;
                }
                if (i < digits - 1)
                    result += (x[x.Length - 1] / 10).ToString();
                r[x.Length - 1] = x[x.Length - 1] % 10; ;
                for (int j = 0; j < x.Length; j++)
                    x[j] = r[j] * 10;
            }

            return result;
        }
        public class StringSearch
        {   // Call Found one character at a time until string found
            private readonly string value;
            private readonly List<int> indexList = new List<int>();
            public StringSearch(string value)
            {
                this.value = value;
            }
            public bool Found(int nextChar)
            {
                for (int index = 0; index < indexList.Count; )
                {
                    int valueIndex = indexList[index];
                    if (value[valueIndex] == nextChar)
                    {
                        ++valueIndex;
                        if (valueIndex == value.Length)
                        {
                            indexList[index] = indexList[indexList.Count - 1];
                            indexList.RemoveAt(indexList.Count - 1);
                            return true;
                        }
                        else
                        {
                            indexList[index] = valueIndex;
                            ++index;
                        }
                    }
                    else
                    {   // next char does not match
                        indexList[index] = indexList[indexList.Count - 1];
                        indexList.RemoveAt(indexList.Count - 1);
                    }
                }
                if (value[0] == nextChar)
                {
                    if (value.Length == 1)
                        return true;
                    indexList.Add(1);
                }
                return false;
                }
                public void Reset()
                {
                    indexList.Clear();
                }
        }
        }
    }

