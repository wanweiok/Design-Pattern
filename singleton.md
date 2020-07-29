# Singleton

事项 | 说明
---|---
目的 | 使用户只能创建类的单一实例
实现 | 隐藏类的构造函数；静态唯一的成员变量
例子 | 数据库访问的单一入口，可以很容易的控制检查、计数、锁等机制来强制实施访问和结构方面的约定
好处 | 跨平台；适用于任何类；可以通过派生创建；延迟求值
代价 | 摧毁方法未定义；不能继承；效率问题；不透明性


```
public interface UserDatabase{
    User readUser(String userName);
    void writeUser(User user);
}

public class UserDatabaseSource implement UserDatabase
{
    private static UserDatabase theInstrance = new UserDatabaseSource();
    
    public static UserDatabase instance(){
        return theInstance;
    }
    
    public User readUser(String userName){
        //some implementation
        return null;
    }
    public void writeUser(User user){
        //some implementation
    }
}
```
