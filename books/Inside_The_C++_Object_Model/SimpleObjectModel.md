####简单对象模型
	class Point{
		public:
			Point(float xval);
			virtual ~Point();

			float x() const;
			static int PointCount();

		protected:
			virtual ostream&
				print( ostream &os) const;

				float _x;
				static int _point_count;
	};

	//members本身不放在object之中,只有指向member的指针才放在object内,这么做可以避免members有不同类型,因而需要不同的存储空间,所招致问题

	//object中的members是以slot的索引值来寻址,
	//一个对象的大小: 指针大小乘以class中所声明的member数目
