#ifndef __NEATLINKGENE_HPP__
#define __NEATLINKGENE_HPP__

class NEATLinkGene {
public:
    NEATLinkGene(float weight, unsigned from, unsigned to, bool enabled, bool recurrent)
    : weight_(weight), from_(from), to_(to), enabled_(enabled), recurrent_(recurrent) {}
private:
    float weight_;
    unsigned from_;
    unsigned to_;
    bool enabled_;
    bool recurrent_;
};

#endif // __NEATLINKGENE_HPP__