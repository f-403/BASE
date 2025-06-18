namespace 委托
{
    internal class Program
    {
        
        public static void add(int a, int b)//加static是因为在Main中
        {
            Console.WriteLine(a + b);
        }
        public static void myprint(int a, int b) {  
            Console.WriteLine("test from myprint()");
        }
        delegate void MyD(int a, int b);//委托定义

        static void Main(string[] args)
        {         
            MyD myd;
            myd = add;
            myd(1, 2);
            myd += myprint;//添加另一个函数进列表
            myd(3, 4);//此调用会执行列表中的所有方法
            Console.WriteLine("-----------------");
            Delegate[] all_myd = myd.GetInvocationList();
            for (int i = 0; i < all_myd.Length; i++)
            {
                Console.WriteLine(all_myd[i].Method.Name);//打印方法
            }
        }
    }
}
