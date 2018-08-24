#ifndef CMAP_HPP
#define CMAP_HPP

#include <map>
#include "define.hpp"
#include "sele.hpp"
#include "config.hpp"

class ContactMap {
    protected:
        Selection AtomSele1;
        Selection AtomSele2;
        std::vector<Vec3d>  CordSele1;
        std::vector<Vec3d>  CordSele2;
        std::map<Int2d, Int> Cmap;
    public:
        ContactMap(Selection sele1, Selection sele2);
        bool processDcdData(const Config& config, const Int& psf_natom);
        void buildContactMap(const Int& dim1, const Int& dim2, const float& rcut2); 
        void writeContactMap(const Str& out_pref, const Int& iframe);
};

#endif