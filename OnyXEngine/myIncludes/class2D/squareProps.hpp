#ifndef SQUAREPROPS_HPP
# define SQUAREPROPS_HPP

# include "props.hpp"


class SquareProps : public Props
{
	public:
		SquareProps(Vector2 pos, Vector2 size, int blocking, Color color,
				Texture2D texture, int nbr, std::string name);
		SquareProps(SquareProps const &src);
		~SquareProps(void);

		SquareProps	&operator=(SquareProps const &rhs);
//**************************************************************//
	// Modification //
		void		ftSetSpeedModifier(float speed, char c);
		void		ftSetSpeedX(float speed);
		void		ftSetSpeed(float speed);

		void		ftChangeSpeedModifier(float speed, char c);
		void		ftChangeSpeedX(float speed);
		void		ftChangeSpeed(float speed);

//**************************************************************//
	// Return //
		float		ftReturnSpeedModifier(char c) const;
		float		ftReturnSpeedX(char c) const;
		float		ftReturnSpeed(void) const;


	protected:
		Vector2				_speedModifier;
		float				_speed;
		float				_speedX;
};

#endif