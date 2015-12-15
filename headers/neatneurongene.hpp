#ifndef __NEATNEURONGENE_HPP__
#define __NEATNEURONGENE_HPP__

class NEATNeuronGene {
public:
    enum class GeneType {
        Input,
        Bias,
        Output,
        Hidden
    };
    
    NEATNeuronGene(GeneType type): type_(type) {}
private:
    GeneType type_;
};

#endif // __NEATNEURONGENE_HPP__