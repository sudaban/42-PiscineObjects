#ifndef LINKABLE_PART_HPP
#define LINKABLE_PART_HPP


class LinkablePart
{
public:
    virtual ~LinkablePart() {}
    virtual void Execute(float p_pression) = 0;
};


#endif
