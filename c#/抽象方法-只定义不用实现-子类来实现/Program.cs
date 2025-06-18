namespace 抽象方法_只定义不用实现_子类来实现
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            Not_abs no_abs = new Not_abs();
            no_abs.test2();
        }
    }
    //抽象类可以有不抽象方法，但有抽象方法的类一定要是抽象类
    //如果子类也是抽象的，可以不重写父类的抽象方法， 让子类下面的非抽象类来重写
    //抽象类不能实例化
    public abstract class Base {
        void test() {
            Console.WriteLine();
        }
        public abstract void test2();//这里写实现代码会报错
        //
    }
    //这个子类也是抽象的，所以不用重写Base的test2方法
    public abstract class Abs_too : Base
    {

    }
    public class  Not_abs:Abs_too
        {
        override public void test2() {
            Console.WriteLine("重写了Base.test2()方法");
        }
        
        }
}
