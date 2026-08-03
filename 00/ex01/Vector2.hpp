#ifndef VECTOR2_HPP
# define VECTOR2_HPP

class Vector2
{
private:
	float m_x;
	float m_y;

public:
	Vector2();
	Vector2(float p_x, float p_y);
	Vector2(const Vector2& p_other);
	Vector2& operator=(const Vector2& p_other);
	~Vector2();

	float m_x_getter() const;
	float m_y_getter() const;

	void m_x_setter(float p_x);
	void m_y_setter(float p_y);

	bool operator==(const Vector2& p_other) const;
	bool operator!=(const Vector2& p_other) const;
};

#endif
