
#ifndef __MD5_H__
#define __MD5_H__


typedef unsigned       int uint4;
typedef unsigned short int uint2;
typedef unsigned      char uchar;


class md5
{
// Methods
public:

	static std::string PrintMD5(uchar md5Digest[8]);
	static std::string MD5String(const char* szString);

	md5() { Init(); }
	void	Init();
	void	Update(uchar* chInput, uint4 nInputLen);
	void	Finalize();
	uchar*	Digest() { return m_Digest; }

private:

	void	Transform(uchar* block);
	void	Encode(uchar* dest, uint4* src, uint4 nLength);
	void	Decode(uint4* dest, uchar* src, uint4 nLength);


	inline	uint4	rotate_left(uint4 x, uint4 n)
	                 { return ((x << n) | (x >> (32-n))); }

	inline	uint4	F(uint4 x, uint4 y, uint4 z)
	                 { return ((x & y) | (~x & z)); }

	inline  uint4	G(uint4 x, uint4 y, uint4 z)
	                 { return ((x & z) | (y & ~z)); }

	inline  uint4	H(uint4 x, uint4 y, uint4 z)
	                 { return (x ^ y ^ z); }

	inline  uint4	I(uint4 x, uint4 y, uint4 z)
	                 { return (y ^ (x | ~z)); }

	inline	void	FF(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac)
	                 { a += F(b, c, d) + x + ac; a = rotate_left(a, s); a += b; }

	inline	void	GG(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac)
                     { a += G(b, c, d) + x + ac; a = rotate_left(a, s); a += b; }

	inline	void	HH(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac)
                     { a += H(b, c, d) + x + ac; a = rotate_left(a, s); a += b; }

	inline	void	II(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac)
                     { a += I(b, c, d) + x + ac; a = rotate_left(a, s); a += b; }

// Data
private:
	uint4		m_State[4];
	uint4		m_Count[2];
	uchar		m_Buffer[64];
	uchar		m_Digest[16];
	uchar		m_Finalized;

};


#endif /* __MD5_H__ */