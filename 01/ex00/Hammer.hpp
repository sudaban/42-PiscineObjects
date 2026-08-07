#ifndef HAMMER_HPP
# define HAMMER_HPP

# include "Tool.hpp"

class Hammer : public Tool
{
public:
	Hammer(void);
	Hammer(const Hammer &p_other);
	Hammer &operator=(const Hammer &p_other);
	virtual	~Hammer(void);

	virtual void				Use(void);
	virtual const std::string	&GetTypeName(void) const;

	static const std::string	TYPE_NAME;
};

#endif
