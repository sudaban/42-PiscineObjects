#ifndef TOOL_HPP
# define TOOL_HPP

# include <iostream>
# include <string>

class Worker;

class Tool
{
public:
	Tool(void);
	Tool(const Tool &p_other);
	Tool &operator=(const Tool &p_other);
	virtual	~Tool(void);

	virtual void				Use(void) = 0;
	virtual const std::string	&GetTypeName(void) const = 0;

	int				GetNumberOfUses(void) const;
	void			IncrementUses(void);

	Worker			*GetOwner(void) const;
	void			SetOwner(Worker *p_owner);

protected:
	int				m_number_of_uses;
	Worker			*m_owner;
};

#endif
