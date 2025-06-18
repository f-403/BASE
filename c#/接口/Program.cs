namespace 接口
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
        }
    }

    public interface IFoo {
        /*
         接口的 { get; set; } → 只是声明，必须由实现类提供具体逻辑。
        普通类的 { get; set; } → 自动实现，可以直接使用。
        抽象类的 { get; set; } → 可以是自动属性，也可以是 abstract 强制子类实现。
         
         */
        //如果接口没实现在方法，子类必定要重写，抽象类与普通类能有字段，接口不能有字段，可以有属性
        //如果父类中只有get或set, 可以只重写get或set, 或者两个都写
        int age {
        //手动实现属性
        set
            {
                this.age = value;
            }
         get
            {
                return this.age;
            }
        }

        //只有一个get方法获取属性
        public int test { get; }
    }
    class Test : IFoo
    {
     
        public int test {
            //set { } //父类中没有set方法， 这里可以不重写
            get{ return this.test; }
        }

    }
}
