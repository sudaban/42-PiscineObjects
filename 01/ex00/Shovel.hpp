#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include "Tool.hpp"

class Shovel : public Tool
{
public:
	Shovel(void);
	Shovel(const Shovel &p_other);
	Shovel &operator=(const Shovel &p_other);
	virtual	~Shovel(void);

	virtual void				Use(void);
	virtual const std::string	&GetTypeName(void) const;

	static const std::string	TYPE_NAME;
};

#endif
