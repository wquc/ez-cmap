#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "psf.hpp"
#include "util.hpp"

bool PSF::readPsfData(const Str& inp_name) {
    std::cout << "ReadPSF> Reading PSF info from file: " << inp_name << std::endl;
    std::ifstream inp_file(inp_name);
    if(!inp_file.is_open())
        return error_exit<bool>("Cannot open PSF file.", false);

    std::regex r_psfatom("^\\s+\\d+\\s\\w+\\s\\d+\\s+\\w+\\s{2}\\w+.*");
    Str each_line;
    std::stringstream each_stream;
    while (getline(inp_file, each_line)) {
        if (std::regex_match(each_line, r_psfatom)) {
            PsfAtom tmp_atom;
            each_stream.clear();
            each_stream.str(each_line);
            each_stream >> tmp_atom.atomid
                        >> tmp_atom.segid
                        >> tmp_atom.resid 
                        >> tmp_atom.resname
                        >> tmp_atom.type;
            PsfData.push_back(tmp_atom);
        }
    }
    this->psf_natom = PsfData.size();
    std::cout << "ReadPSF> After reading, (" 
              << this->psf_natom
              << ") atoms were recorded."
              << std::endl;
    return true;
}

std::vector<PsfAtom> const& PSF::getPsfData() const {
    return this->PsfData;
}

Int PSF::getPsfNatom(void) const {
    return this->psf_natom;
}