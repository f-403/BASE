namespace 密封类与方法dealed
{
    internal class Program
    {
        static void Main(string[] args)
        {
    /*
        virtual 与 abstract 关键字的区别
    在 C# 中，virtual 和 abstract 都用于实现方法的多态性（允许子类重写父类的方法），但它们有重要的区别：

    特性	                        virtual	                              abstract
    是否必须被重写？	            ❌ 子类可选重写	✅                   子类必须重写（除非子类也是 abstract）
    能否有方法体？	                ✅ 可以有默认实现	                  ❌ 不能有方法体（只有声明）
    适用场景	                    父类提供默认实现，子类可选择修改	  父类只定义规范，强制子类实现
    能用在哪些成员上？	            方法、属性、索引器、事件	          方法、属性、索引器、事件
    能否用于静态方法？	            ❌ 不能	                              ❌ 不能
    所在的类是否必须为abstract？	❌ 普通类可用	                      ✅ 只能在 abstract 类中声明
             */
        }
    }
    sealed class N_from {
        //此类不能继承
    }
    class Test_seald {
        public virtual void test() { }
    }
    class Have_seald_function:Test_seald
    {
        /*
        密封类(sealed class)：不能被继承。
        密封方法(sealed override)：
        只能用于重写的方法（必须有 virtual 或 abstract 基方法）。
        作用是阻止派生类进一步重写该方法。
        */
        public sealed override void test() { }
    }
}
