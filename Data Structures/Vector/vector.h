#include <memory>
#include <iterator>

#ifndef _vector_H_
#define _vector_H_
//-------------------------------------------------------------------------------------------------
namespace htk
{
	template <typename type, typename allocator = std::allocator<type>>
	class vector
	{
	public:
		//Member types
		class iterator;
		class const_iterator;
		using value_type = type;
		using allocator_type = allocator;
		using size_type = std::size_t;
		using diference_type = std::ptrdiff_t;
		using reference = value_type &;
		using const_reference = const value_type &;
		using pointer = typename std::allocator_traits<allocator>::pointer;
		using const_pointer = typename std::allocator_traits<allocator>::const_pointer;
		class iterator;
		class const_iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		//Member functions
		vector() noexcept(noexcept(allocator()));
		explicit vector(const allocator & alloc) noexcept;
		vector(const vector & vec);
		vector(vector && vec);
		vector & operator = (const vector & vec);
		vector & operator = (vector && vec);
		~vector();
		allocator_type get_allocator() const;

	private:
		allocator_type allocatort;
		size_type m_size;
		size_type m_capacity;
	private:
		inline void reallocate();
	};
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	vector<type, allocator>::vector() noexcept(noexcept(allocator()))
	{

	}
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	vector<type, allocator>::vector(const allocator & alloc) noexcept
	{
	
	}
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	vector<type, allocator>::vector(const vector & vec)
	{

	}
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	vector<type, allocator>::vector(vector && vec)
	{

	}
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	vector<type, allocator> & vector<type, allocator>::operator = (const vector & vec)
	{
		return;
	}
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	vector<type, allocator> & vector<type, allocator>::operator = (vector && vec)
	{
		return;
	}
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	vector<type, allocator>::~vector()
	{

	}
	//-------------------------------------------------------------------------------------------------
	template <typename type, typename allocator>
	typename vector<type, allocator>::allocator_type vector<type, allocator>::get_allocator() const
	{

	}
	//-------------------------------------------------------------------------------------------------
}
#endif // _vector_H_