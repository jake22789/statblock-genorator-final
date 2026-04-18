#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

std::array<int, 6> generateSixRandomNumbers(std::mt19937_64& rng)
{
    std::uniform_int_distribution<int> dist(6, 22);
    std::array<int, 6> numbers{};

    for (auto &value : numbers)
    {
        value = dist(rng);
    }

    return numbers;
}

std::array<int, 6> mapArrayToEquation(const std::array<int, 6>& input)
{
    std::array<int, 6> output{};

    for (size_t i = 0; i < input.size(); ++i)
    {
        output[i] = (input[i] - 10.0) / 2.0;
    }

    return output;
}

template <typename T, size_t N>
void printArray(const std::array<T, N>& arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i + 1 < arr.size())
            std::cout << ' ';
    }
    std::cout << '\n';
}

std::unordered_map<std::string, int> generateskills(const std::array<int, 6>& modifiers, int level, std::mt19937_64& rng)
{
    int proficiency_bonus = 2 + (level - 1) / 4;
    std::unordered_map<std::string, int> skills;
    skills["swordattack"] = modifiers[0] + proficiency_bonus;
    skills["Athletics"] = modifiers[0];

    skills["bowattack"] = modifiers[1] + proficiency_bonus;
    skills["Acrobatics"] = modifiers[1];
    skills["Sleight of Hand"] = modifiers[1];
    skills["Stealth"] = modifiers[1];

    skills["Cooking"] = modifiers[2];

    skills["Arcana"] = modifiers[3];
    skills["History"] = modifiers[3];
    skills["Nature"] = modifiers[3];
    skills["Religion"] = modifiers[3];
    skills["Investigation"] = modifiers[3];

    skills["Animal Handling"] = modifiers[4];
    skills["Insight"] = modifiers[4];
    skills["Medicine"] = modifiers[4];
    skills["Perception"] = modifiers[4];
    skills["Survival"] = modifiers[4];
    
    skills["Performance"] = modifiers[5];
    skills["Persuasion"] = modifiers[5];
    skills["Deception"] = modifiers[5];
    skills["Intimidation"] = modifiers[5];

    skills["MagicAttack"] = modifiers[5] + proficiency_bonus;

    // List of skills that can gain proficiency
    std::vector<std::string> skill_names = {
        "Athletics", "Acrobatics", "Sleight of Hand", "Stealth", "Cooking",
        "Arcana", "History", "Nature", "Religion", "Investigation",
        "Animal Handling", "Insight", "Medicine", "Perception", "Survival",
        "Performance", "Persuasion", "Deception", "Intimidation"
    };

    // Shuffle the list
    std::shuffle(skill_names.begin(), skill_names.end(), rng);

    // Add proficiency bonus to the first 5 skills
    for (size_t i = 0; i < 5 && i < skill_names.size(); ++i)
    {
        skills[skill_names[i]] += proficiency_bonus;
    }

    return skills;
}

std::string formatModifier(int value)
{
    return (value >= 0 ? "+" : "") + std::to_string(value);
}
std::string generateName(std::mt19937_64& rng)
{
    static std::vector<std::string> names = {  // AI was used to generate these names,
        "Aragorn", "Legolas", "Gimli", "Frodo", "Gandalf",
        "Eowyn", "Boromir", "Samwise", "Pippin", "Merry",
        "Kaelith", "Tharion", "Elowen", "Bryndor", "Sylvara",
    "Draven", "Liora", "Fenric", "Mirella", "Cairos",
    "Vaelric", "Isolde", "Garrick", "Seraphine", "Torvan",
    "Eryndor", "Lyraeth", "Dareth", "Althaea", "Korrin",
    "Virel", "Thessalia", "Roderic", "Nymeria", "Corvyn",
    "Selindra", "Ormund", "Faylen", "Brenric", "Ilyana",
    "Kaedric", "Morrigan", "Theron", "Aeloria", "Gryffin",
    "Luthar", "Elaris", "Valindra", "Drystan", "Caelith",
    "Rhiannon", "Jorund", "Saphira", "Daelor", "Thyra",
    "Zeric", "Meliora", "Fenwyn", "Alaric", "Isilwen",
    "Varyn", "Tessara", "Corvinus", "Luneth", "Elaria",
    "Daeric", "Myrrhyn", "Sylvaris", "Kaelora", "Branthor",
    "Thalindra", "Eryndra", "Cyrion", "Faylinn", "Mordrin",
    "Lysara", "Vandric", "Iselwyn", "Darian", "Caelynn",
    "Orinath", "Selvryn", "Jareth", "Valoria", "Rynric",
    "Fionel", "Altharion", "Myrrith", "Theris", "Elvran",
    "Kythera", "Bryndis", "Zephran", "Liorael", "Darvyn",
    "Veylith", "Aeloria", "Garron", "Melyndra", "Thorian",
    "Isariel", "Corveth", "Sylvarael", "Kaelor", "Rhieryn",
    "Faelric", "Taryndra", "Dreneth", "Elyndra", "Vorrick",
    "Alariel", "Brython", "Mirelith", "Jorwyn", "Selthara",
    "Dravenor", "Lyrielle", "Caelwyn", "Fendral", "Isolynn",
    "Vandral", "Therion", "Elthara", "Gryndor", "Maerwen",
    "Korveth", "Sylrion", "Aelith", "Thyrell", "Eryndra",
    "Valric", "Lunaria", "Drysthael", "Cyralith", "Fayloren",
    "Morriveth", "Kaelara", "Toryn", "Selindra", "Jorynth",
    "Raventh", "Isalyn", "Veydrin", "Althar", "Mirelwyn",
    "Thessalyn", "Darianth", "Corvella", "Lytherin", "Fenara",
    "Bryndral", "Elarion", "Gryndel", "Caelyr", "Therwyn",
    "Orveth", "Sylvanna", "Kaedryn", "Vandrel", "Elisara",
    "Dravon", "Lyrieth", "Roderan", "Thalorin", "Faylora",
    "Morriveth", "Alarion", "Jorvyn", "Selthryn", "Daerith",
    "Veylora", "Cyrionel", "Iselara", "Brythar", "Thyrelle",
    "Eryndral", "Gryffinor", "Caelithen", "Liorael", "Vandricen",
    "Fendralith", "Aeloriah", "Drysthal", "Rhieryth", "Maerith",
    "Korvethan", "Sylvarin", "Althariel", "Thoryn", "Elvrielle",
    "Kytheriel", "Brynthar", "Zephyra", "Darvion", "Veylithen",
    "Therionel", "Mirelyth", "Caelynnor", "Jorynthia", "Selvaris",
    "Orindral", "Lyrielleth", "Fenricel", "Bryndiseth", "Garrion",
    "Elariseth", "Thalindrae", "Faylinnor", "Mordrion", "Lysariel",
    "Valindral", "Iselwynor", "Dariandel", "Caelynth", "Orinathor"
    };
    std::uniform_int_distribution<size_t> dist(0, names.size() - 1);
    return names[dist(rng)];
}

std::string generateClass(std::mt19937_64& rng)
{
    static const std::array<std::string, 9> classes = {
        "wizard", "rouge", "fighter", "bard", "barbarian",
        "cleric", "druid", "sorcerer", "artificer"
    };

    std::uniform_int_distribution<size_t> dist(0, classes.size() - 1);
    return classes[dist(rng)];
}

void printnewStatBlock(int level, std::mt19937_64& rng)
{
    std::array<std::string, 6> stat_names = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};
    auto name = generateName(rng);
    auto characterClass = generateClass(rng);
    auto stats = generateSixRandomNumbers(rng);
    auto roll_modifiers = mapArrayToEquation(stats);
    auto skills = generateskills(roll_modifiers, level, rng);
    int health_points = 10 * level + level * roll_modifiers[2];
    std::cout << "Level: " << level << " HP: " << health_points << "  Name: " << name << "  Class: " << characterClass << "\n";
    const int columnWidth = 10;
    for (size_t i = 0; i < stat_names.size(); ++i)
        std::cout << std::setw(columnWidth) << std::right << stat_names[i];
    std::cout << '\n';

    for (size_t i = 0; i < stats.size(); ++i)
        std::cout << std::setw(columnWidth) << std::right << stats[i];
    std::cout << '\n';

    for (size_t i = 0; i < roll_modifiers.size(); ++i)
        std::cout << std::setw(columnWidth) << std::right << formatModifier(roll_modifiers[i]);
    std::cout << "\n";

    std::vector<std::string> skillOrder = {
        "swordattack","bowattack","MagicAttack","Athletics", "Acrobatics", "Sleight of Hand", "Stealth",
        "Cooking", "Arcana", "History", "Nature", "Religion", "Investigation",
        "Animal Handling", "Insight", "Medicine", "Perception", "Survival",
        "Performance", "Persuasion", "Deception", "Intimidation"
    };

    size_t half = (skillOrder.size() + 1) / 2;
    const int nameWidth = 18;
    const int valueWidth = 4;

    for (size_t row = 0; row < half; ++row)
    {
        const std::string& leftName = skillOrder[row];
        std::cout << std::setw(nameWidth) << std::left << leftName
                  << std::setw(valueWidth) << std::right << formatModifier(skills[leftName]);

        size_t rightIndex = row + half;
        if (rightIndex < skillOrder.size())
        {
            const std::string& rightName = skillOrder[rightIndex];
            std::cout << "  " << std::setw(nameWidth) << std::left << rightName
                      << std::setw(valueWidth) << std::right << formatModifier(skills[rightName]);
        }

        std::cout << '\n';
    }
}

void generatestatblocks(int count, int level, std::mt19937_64& rng)
{
    for (int i = 0; i < count; ++i)
    {
        printnewStatBlock(level, rng);
        if (i < count - 1) std::cout << "\n";
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <number_of_statblocks> <level> <seed>\n";
        return 1;
    }

    int count = std::stoi(argv[1]);
    int level = std::stoi(argv[2]);
    unsigned long long seed = std::stoull(argv[3]);

    std::mt19937_64 rng(seed);
    generatestatblocks(count, level, rng);

    return 0;
}