NAME        = animal

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# 源文件
SRCS        = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

# obj 文件夹
OBJDIR      = obj

# 对应 obj 文件夹下的目标文件
OBJS        = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# 默认规则：先创建 obj 文件夹，再编译
all: $(OBJDIR) $(NAME)

# 链接可执行文件
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# 创建 obj 文件夹
$(OBJDIR):
	mkdir -p $(OBJDIR)

# 编译规则，把源文件编译到 obj 文件夹
# | $(OBJDIR) 表示 obj 文件夹作为 order-only 依赖（只需存在，不触发重编译）
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理 obj 文件夹
clean:
	rm -rf $(OBJDIR)

# 完全清理，包括可执行文件
fclean: clean
	rm -f $(NAME)

# 重新编译
re: fclean all

.PHONY: all clean fclean re