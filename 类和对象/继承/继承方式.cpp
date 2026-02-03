//继承方式有三种：
//		公共继承、保护继承、私有继承
/*
现在举例：
		A类为父类，有三个成员，分别为public、protected、private.

		B、C、D为A的子类，B为共有继承，C为保护继承，D为私有继承
		现在B、C、D的继承结果如下：

		A的private属性谁都不可访问
		B继承的其余属性与A的一模一样
		C也继承了其余所有属性，但权限全部为protected
		D与C相同，但权限为private


*/