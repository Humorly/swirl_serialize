# swirl_serialize
# 构建流程
cmake .
cmake --build . --parallel

# 生成序列化文件
	SerializationTool.exe -s data_declaration.h -d data_serialize.h     // Windows
	SerializationTool -s data_declaration.h -d data_serialize.h         // Linux & Mac

# 测试代码
	student s1 { 20, "chen", "man", { 1, 2, 3, 4, 5, 6 } };
	// 序列化
	std::string str = wstd::serialize(s1);
	student s2;
	// 反序列化
	wstd::deserialize(s2, nlohmann::json::parse(str));
