<template>
    <table class="table table-hover">
        <tbody>
            <tr>
                <td>Bootloader Version</td>
                <td>{{ formatVersion(devInfoList.fw_bootloader_version) }}</td>
            </tr>
            <tr>
                <td>Firmware Version</td>
                <td>{{ formatVersion(devInfoList.fw_build_version) }}</td>
            </tr>
            <tr>
                <td>Firmware Build Date</td>
                <td>{{ devInfoList.fw_build_datetime }}</td>
            </tr>
            <tr>
                <td>Hardware Part Number</td>
                <td>{{ devInfoList.hw_part_number }}</td>
            </tr>
            <tr>
                <td>Hardware Version</td>
                <td>{{ devInfoList.hw_version }}</td>
            </tr>
        </tbody>
    </table>
</template>

<script lang="ts">
import { defineComponent } from 'vue';

declare interface DevInfoData {
    fw_bootloader_version: number,
    fw_build_version: number,
    fw_build_datetime: Date,
    hw_part_number: number,
    hw_version: number
}

export default defineComponent({
    props: {
        devInfoList: { type: Object as () => DevInfoData, required: true },
    },
    computed: {
        formatVersion() {
            return (value: number) => {
                const version_major = Math.floor(value / 10000);
                const version_minor = Math.floor((value - version_major * 10000) / 100);
                const version_patch = Math.floor((value - version_major * 10000 - version_minor * 100));
                return version_major + "." + version_minor + "." + version_patch;
            };
        }
    }
});
</script>